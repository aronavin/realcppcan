#ifndef VISORCAN_H
#define VISORCAN_H

#include <linux/can.h>

#include <mutex>
#include <queue>
#include <atomic>
#include <memory>
#include <cstdint>
#include <functional>

#define VISOR_BEGIN_NAMESPACE \
    namespace visor           \
    {
        
#define VISOR_END_NAMESPACE }

VISOR_BEGIN_NAMESPACE

enum {

    MIN_STANDARD_ID = 0x000,
    MAX_STANDARD_ID = 0x7FFU,
    MIN_EXTENDED_ID = 0x10000000U,
    MAX_EXTENDED_ID = 0x1FFFFFFFU
};

enum {

    MAX_FRAME_LENGTH = 8
};

using frameid_t = uint32_t;

class CanBusImpl;

class CanFrame
{
public:
    CanFrame() noexcept;
    ~CanFrame() noexcept;

    CanFrame(const CanFrame &other) noexcept;
    CanFrame(CanFrame &&other) noexcept;

    CanFrame(frameid_t id,
             const std::vector<uint8_t> &data,
             bool setExtended = false);

    CanFrame(frameid_t id, const std::string &data, bool setExtended = false);

    CanFrame(frameid_t id,
             const uint8_t *data,
             size_t size,
             bool setExtended = false);

    CanFrame &operator=(const CanFrame &other) noexcept;
    CanFrame &operator=(CanFrame &&other) noexcept;

    bool operator==(const CanFrame &other) const noexcept;

    friend std::ostream &operator<<(std::ostream &os, const CanFrame &frame);

    frameid_t frameId() const noexcept;
    void setFrameId(const frameid_t id, bool isExtended = false) noexcept;

    uint8_t length() const noexcept;

    void setData(const std::vector<uint8_t> &data);
    void setData(const std::string &data);
    void setData(const uint8_t *data, const size_t size);

    std::vector<uint8_t> data() const;
    std::string stringData() const;

    bool isValid() const noexcept;

    bool isExtendedFrame() const noexcept;

    friend class CanBus;

private:
    CanFrame(bool isValid) noexcept;

    void setRaw(const can_frame frame);
    can_frame raw() const;

    void setValidity(const bool);

private:
    can_frame m_frame;
};


class CanBus
{
public:
    enum CanBusError {

        NO_ERROR,
        OPEN_FAILURE,
        WRITE_FAILURE,
        READ_FAILURE,
        UNKNOWN_ERROR
    };

public:
    CanBus();
    explicit CanBus(const std::string &deviceName);
    ~CanBus();

    bool open();
    void close();

    bool isOpen() const;

    bool writeFrame(const CanFrame &frame);
    bool readFrame(CanFrame &frame);

    void setDeviceName(const std::string &name);
    std::string deviceName() const;

    bool waitForFrame(const int32_t timeout_ms = 3000);

    void setReceiveCallback(const std::function<void()> &function);

    void clearReceiveQueue();

    int getAvailableFrameCount() const;

    CanBusError error() const;
    std::string errorString() const;

private:
    void startCanFrameListener();

    void stopCanFrameListener();

    void updateQueue();

    void setError(const CanBus::CanBusError code, const std::string &string);

    void clearError();

private:
    friend class CanBusImpl;

    std::unique_ptr<CanBusImpl> impl;
};

VISOR_END_NAMESPACE

#endif // VISORCAN_H
