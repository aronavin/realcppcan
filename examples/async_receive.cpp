#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <functional>

#include "../include/visorcan.h"

void canReceiveCallback(visor::CanBus &);

int main(int argc, char **argv)
{

    visor::CanBus vcan;

    std::string interface("vcan0");

    vcan.setDeviceName(interface);

    if (!vcan.open())
    {

        std::cerr << "Error opening CAN bus: " << vcan.errorString() << std::endl;

        return 1;
    }

    vcan.setReceiveCallback([&vcan] { canReceiveCallback(vcan); });

    while (1)
    {

        std::cout << "Main thread running..." << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}

void canReceiveCallback(visor::CanBus &vcan)
{

    visor::CanFrame frame;

    vcan.readFrame(frame);

    if (!frame.isValid())
    {

        std::cout << "Invalid command received" << std::endl;

        return;
    }

    std::cout << vcan.deviceName() << frame;

    std::cout << "( " << frame.stringData() << " )" << std::endl;
}
