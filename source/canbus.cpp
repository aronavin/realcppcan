#include <fcntl.h>
#include <net/if.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>

#include "visorcan.h"

VISOR_BEGIN_NAMESPACE

class CanBusImpl
{
public:

    ~CanBusImpl() {

        if (m_fileDescriptor != -1) {
            
            reset();
        }
    }

private:
    friend class CanBus;

    CanBusImpl()
        : m_fileDescriptor(-1), m_deviceName(std::string()),
          m_errorCode(CanBus::CanBusError::NO_ERROR),
          m_errorString(std::string()), m_receiveThreadStopFlag(true) {}

    CanBusImpl(const std::string &deviceName)
        : m_fileDescriptor(-1), m_deviceName(deviceName),
          m_errorCode(CanBus::CanBusError::NO_ERROR),
          m_errorString(std::string()), m_receiveThreadStopFlag(true) {}

    void reset()
    {
        clearQueue();

        m_deviceName = std::string();

        m_errorCode = CanBus::CanBusError::NO_ERROR;

        m_errorString = std::string();

        m_receiveThreadStopFlag = true;

        m_fileDescriptor = -1;
    }

    int fileDescriptor() const { return m_fileDescriptor.load(); }

    void setFileDescriptor(const int fileDescriptor)
    {
        m_fileDescriptor.store(fileDescriptor);
    }

    int errorCode() const { return m_errorCode.load(); }

    void setErrorCode(const int errorCode) { m_errorCode.store(errorCode); }

    bool receiveThreadStopFlag() const { return m_receiveThreadStopFlag.load(); }

    void setReceiveThreadStopFlag(const bool &receiveThreadStopFlag)
    {
        m_receiveThreadStopFlag.store(receiveThreadStopFlag);
    }

    std::string deviceName() const
    {
        std::lock_guard<std::mutex> lock(m_deviceMutex);

        return m_deviceName;
    }

    void setDeviceName(const std::string &deviceName)
    {
        std::lock_guard<std::mutex> lock(m_deviceMutex);

        m_deviceName = deviceName;
    }

    std::string errorString() const
    {
        std::lock_guard<std::mutex> lock(m_errorMutex);

        return m_errorString;
    }

    void setErrorString(const std::string &errorString)
    {
        std::lock_guard<std::mutex> lock(m_errorMutex);

        m_errorString = errorString;
    }

    void setReceiveCallback(const std::function<void()> &receiveCallback)
    {
        std::lock_guard<std::mutex> lock(m_receiveCallbackMutex);

        m_receiveCallback = receiveCallback;
    }

    void runReceiveCallback()
    {
        std::lock_guard<std::mutex> lock(m_receiveCallbackMutex);

        if (m_receiveCallback)
        {
            m_receiveCallback();
        }
    }

    void enqueue(const CanFrame &frame)
    {
        std::lock_guard<std::mutex> lock(m_queueMutex);

        m_receiveFrameQueue.emplace(frame);
    }

    CanFrame dequeue()
    {
        std::lock_guard<std::mutex> lock(m_queueMutex);

        CanFrame frame = m_receiveFrameQueue.front();

        m_receiveFrameQueue.pop();

        return frame;
    }

    void clearQueue()
    {
        std::lock_guard<std::mutex> lock(m_queueMutex);

        std::queue<CanFrame> empty;

        std::swap(m_receiveFrameQueue, empty);
    }

    bool isQueueEmpty() const
    {
        std::lock_guard<std::mutex> lock(m_queueMutex);

        return m_receiveFrameQueue.empty();
    }

    size_t queueLength()
    {
        std::lock_guard<std::mutex> lock(m_queueMutex);

        return m_receiveFrameQueue.size();
    }

private:
    std::atomic_int m_fileDescriptor;

    std::atomic_int m_errorCode;

    std::atomic_bool m_receiveThreadStopFlag;

    std::string m_deviceName;

    std::string m_errorString;

    std::function<void()> m_receiveCallback;

    std::queue<CanFrame> m_receiveFrameQueue;

    mutable std::mutex m_errorMutex;

    mutable std::mutex m_deviceMutex;

    mutable std::mutex m_receiveCallbackMutex;

    mutable std::mutex m_queueMutex;
};

// implementation

CanBus::CanBus() : impl(new CanBusImpl()) {}

CanBus::CanBus(const std::string &deviceName)
    : impl(new CanBusImpl(deviceName)) {}

CanBus::~CanBus()
{
    if (isOpen())
    {
        close();
    }
}

bool CanBus::open()
{
    if (isOpen())
    {
        setError(CanBus::OPEN_FAILURE, deviceName() + " is already open");

        return false;
    }

    const std::string device = deviceName();

    int fd = socket(PF_CAN, SOCK_RAW | SOCK_NONBLOCK, CAN_RAW);

    if (fd < 0)
    {
        setError(CanBus::OPEN_FAILURE, "failed to open socket");

        return false;
    }

    struct sockaddr_can addr
    {
    };
    struct ifreq ifr
    {
    };

    memcpy(ifr.ifr_name, device.c_str(), device.size());

    if (ioctl(fd, SIOCGIFINDEX, &ifr) != 0)
    {
        fd = -1;

        setError(CanBus::OPEN_FAILURE, "Device not found");

        return false;
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (addr.can_ifindex < 0)
    {
        fd = -1;

        setError(CanBus::OPEN_FAILURE, "Could not find CAN interface");

        return false;
    }

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        fd = -1;

        setError(CanBus::OPEN_FAILURE, "Failed to bind can socket");

        return false;
    }

    impl->setFileDescriptor(fd);

    clearError();

    startCanFrameListener();

    return true;
}

void CanBus::close()
{
    if (!isOpen())
    {
        return;
    }

    ::close(impl->fileDescriptor());

    stopCanFrameListener();

    impl->reset();
}

bool CanBus::writeFrame(const CanFrame &frame)
{
    if (!isOpen())
    {
        setError(CanBus::WRITE_FAILURE, "Device is not opened");

        return false;
    }

    if (!frame.isValid())
    {
        setError(CanBus::WRITE_FAILURE, "Frame provided is invalid");

        return false;
    }

    auto convertedFrame = frame.raw();

    auto bytes = ::write(impl->fileDescriptor(), &convertedFrame,
                         sizeof(struct can_frame));

    if (bytes < 0)
    {
        setError(CanBus::WRITE_FAILURE, "Unable to write");

        return false;
    }

    return true;
}

bool CanBus::readFrame(CanFrame &frame)
{
    if (!isOpen())
    {
        return false;
    }

    if (impl->isQueueEmpty())
    {
        setError(CanBus::READ_FAILURE, "The queue is empty");

        return false;
    }

    frame = impl->dequeue();

    return true;
}

static timeval &get_time_value_in_milliseconds(const int32_t timeout)
{
    static timeval v;

    v.tv_sec = timeout / 1000;
    v.tv_usec = timeout * 1000;

    return v;
}

static int poll_can_frame(int fd, const int32_t timeout_ms)
{
    fd_set readfds;

    FD_ZERO(&readfds);

    FD_SET(fd, &readfds);

    auto timeout = get_time_value_in_milliseconds(timeout_ms);

    return ::select(fd + 1, &readfds, NULL, NULL, &timeout);
}

void CanBus::startCanFrameListener()
{
    impl->setReceiveThreadStopFlag(false);

    std::thread thread([&, this]() {
        while (!impl->receiveThreadStopFlag())
        {
            if (poll_can_frame(impl->fileDescriptor(), 5000) <= 0) {

                continue;
            }

            updateQueue();

            std::this_thread::sleep_for(std::chrono::milliseconds(5));

            impl->runReceiveCallback();
        }
    });

    thread.detach();
}

void CanBus::stopCanFrameListener() { impl->setReceiveThreadStopFlag(true); }

bool CanBus::waitForFrame(const int32_t timeout_ms)
{
    if (!isOpen())
    {
        return false;
    }

    auto start_time = std::chrono::steady_clock::now();

    while (impl->isQueueEmpty())
    {
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                              std::chrono::steady_clock::now() - start_time)
                              .count();

        if (elapsed_ms >= timeout_ms)
        {
            setError(CanBusError::READ_FAILURE,
                     "wait for can frame : timeout occured");

            return false;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    return true;
}

void CanBus::setDeviceName(const std::string &name)
{
    if (isOpen())
    {
        setError(CanBus::UNKNOWN_ERROR,
                 "unable to set device name while device is open");

        return;
    }

    clearError();

    impl->setDeviceName(name);
}

std::string CanBus::deviceName() const { return impl->deviceName(); }

CanBus::CanBusError CanBus::error() const
{
    return static_cast<CanBusError>(impl->errorCode());
}

std::string CanBus::errorString() const { return impl->errorString(); }

void CanBus::setReceiveCallback(const std::function<void()> &function)
{
    impl->setReceiveCallback(function);
}

void CanBus::clearReceiveQueue() { impl->clearQueue(); }

int CanBus::getAvailableFrameCount() const { return impl->queueLength(); }

static bool read_can_frame(int fd, can_frame &frame)
{
    auto bytes = ::read(fd, &frame, sizeof(struct can_frame));

    if (bytes < 0)
    {
        return false;
    }

    return true;
}

void CanBus::updateQueue()
{
    can_frame old_frame;

    if (read_can_frame(impl->fileDescriptor(), old_frame) == false)
    {
        setError(CanBus::READ_FAILURE, "Unable to read frame");

        return;
    }

    CanFrame frame;

    frame.setRaw(old_frame);

    if (frame.isValid() == false)
    {
        setError(CanBus::READ_FAILURE, "Invalid frame is received");

        return;
    }

    clearError();

    impl->enqueue(frame);
}

bool CanBus::isOpen() const { return (impl->fileDescriptor() > 0); }

void CanBus::setError(const CanBus::CanBusError code,
                      const std::string &string)
{
    impl->setErrorCode(code);
    impl->setErrorString(string);
}

void CanBus::clearError()
{
    impl->setErrorCode(CanBusError::NO_ERROR);
    impl->setErrorString(std::string());
}

VISOR_END_NAMESPACE