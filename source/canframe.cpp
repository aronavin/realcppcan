//
// last edited 2024/08/17
//

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "visorcan.h"

VISOR_BEGIN_NAMESPACE

CanFrame::CanFrame() noexcept
{
    memset(&m_frame, 0, sizeof(can_frame));
}
CanFrame::~CanFrame() = default;

CanFrame::CanFrame(bool isValid) noexcept
{
    memset(&m_frame, 0, sizeof(can_frame));
}

CanFrame::CanFrame(const CanFrame &other) noexcept
{
    setRaw(other.m_frame);
}

CanFrame &CanFrame::operator=(const CanFrame &other) noexcept
{
    if (this != &other)
    {
        setRaw(other.m_frame);
    }

    return *this;
}

CanFrame::CanFrame(CanFrame &&other) noexcept
    : m_frame(std::move(other.m_frame)) {}

CanFrame &CanFrame::operator=(CanFrame &&other) noexcept
{
    if (this != &other)
    {
        m_frame = std::move(other.m_frame);
    }

    return *this;
}

CanFrame::CanFrame(frameid_t id,
                   const std::vector<uint8_t> &data,
                   bool setExtended)
{
    setFrameId(id, setExtended);
    setData(data);
}

// Constructor taking a frame ID and string data
CanFrame::CanFrame(frameid_t id, const std::string &data, bool setExtended)
{
    setFrameId(id, setExtended);
    setData(data);
}

// Constructor taking a frame ID, raw data pointer, and size
CanFrame::CanFrame(frameid_t id,
                   const uint8_t *data,
                   size_t size,
                   bool setExtended)
{
    setFrameId(id, setExtended);
    setData(data, size);
}

void CanFrame::setData(const std::vector<uint8_t> &data)
{
    const auto len = data.size();

    if (len > MAX_FRAME_LENGTH)
    {
        throw std::length_error("CanFrame : data size exceeds the maximum limit");
    }

    std::copy(data.begin(), data.end(), std::begin(m_frame.data));

    m_frame.can_dlc = len;
}

void CanFrame::setData(const uint8_t *data, const size_t size)
{
    if (size > MAX_FRAME_LENGTH)
    {
        throw std::length_error("CanFrame : data size exceeds the maximum limit");
    }

    memcpy(m_frame.data, data, size);

    m_frame.can_dlc = size;
}

void CanFrame::setData(const std::string &data)
{
    const auto len = data.size();

    if (len > MAX_FRAME_LENGTH)
    {
        throw std::length_error("CanFrame : data size exceeds the maximum limit");
    }

    int index = 0;

    for (const auto &c : data)
    {
        m_frame.data[index] = static_cast<uint8_t>(c);

        index++;
    }

    m_frame.can_dlc = len;
}

bool CanFrame::operator==(const CanFrame &other) const noexcept
{
    return (this->frameId() == other.frameId()) &&
           (this->length() == other.length()) &&
           (std::equal(this->data().begin(), this->data().end(),
                       other.data().begin()));
}

std::ostream &operator<<(std::ostream &os, const CanFrame &frame)
{
    os << std::hex << std::setw(2) << std::setfill('0') << std::uppercase
       << frame.frameId() << "  [" << static_cast<int>(frame.length()) << "]  ";

    for (auto byte : frame.data())
    {
        os << static_cast<int>(byte) << " ";
    }
    
    return os;
}

frameid_t CanFrame::frameId() const noexcept
{
    return isExtendedFrame() ? (m_frame.can_id ^ CAN_EFF_FLAG) : m_frame.can_id;
}

void CanFrame::setFrameId(const frameid_t id, bool isExtended) noexcept
{
    if (isExtended) {

        if (id > MAX_EXTENDED_ID) {

            std::cerr << "Warning: Extended ID exceeds maximum value, setting to MAX_EXTENDED_ID" << std::endl;

            m_frame.can_id = MAX_EXTENDED_ID;
        }
        else {

            m_frame.can_id = id | CAN_EFF_FLAG;
        }
    }
    else {

        if (id > MAX_STANDARD_ID) {

            std::cerr << "Warning: Standard ID exceeds maximum value, setting to MAX_STANDARD_ID" << std::endl;

            m_frame.can_id = MAX_STANDARD_ID;
        }
        else {

            m_frame.can_id = id;
        }
    }
}

uint8_t CanFrame::length() const noexcept
{
    return m_frame.can_dlc;
}

std::vector<uint8_t> CanFrame::data() const
{
    std::vector<uint8_t> data;

    std::copy(std::begin(m_frame.data),
              std::begin(m_frame.data) + m_frame.can_dlc,
              std::back_inserter(data));

    return data;
}

std::string CanFrame::stringData() const
{
    std::string asciiString;

    std::transform(
        std::begin(m_frame.data), std::begin(m_frame.data) + m_frame.can_dlc,
        std::back_inserter(asciiString), [](uint8_t byte) { return byte; });

    return asciiString;
}

static bool is_valid_frame_id(uint32_t id, bool isExtended)
{
    if (isExtended) {

        int idd = (id ^ CAN_EFF_FLAG);

        return (idd >= MIN_STANDARD_ID && idd <= MAX_EXTENDED_ID);  
    }

    return (id >= MIN_STANDARD_ID && id <= MAX_STANDARD_ID);
}

bool CanFrame::isValid() const noexcept
{
    return (is_valid_frame_id(m_frame.can_id, isExtendedFrame()) && m_frame.can_dlc <= 8);
}

bool CanFrame::isExtendedFrame() const noexcept
{
    return (m_frame.can_id & CAN_EFF_FLAG);
}

void CanFrame::setRaw(const can_frame frame)
{
    memcpy(&m_frame, &frame, sizeof(can_frame));
}

can_frame CanFrame::raw() const
{
    return m_frame;
}

VISOR_END_NAMESPACE