#include <string>
#include <iostream>

#include "../include/visorcan.h"


int main(int argc, char** argv) {

    std::string interface("vcan0");

    visor::CanBus vcan(interface);

    if (!vcan.open()) {

        std::cerr << "Error opening CAN bus: " << vcan.errorString() << std::endl;
        return 1;
    }

    while (1) {

        if (vcan.waitForFrame() == false) {

            continue;
        }

        visor::CanFrame frame;

        vcan.readFrame(frame);

        if (!frame.isValid()) {

            std::cout << vcan.errorString() << std::endl;
            continue;
        }

        std::cout << interface << " " << frame << std::endl;
    }

    return 0;
}
