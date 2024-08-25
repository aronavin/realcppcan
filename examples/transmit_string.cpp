#include <cstring>
#include <iostream>

#include "../include/visorcan.h"

int convertStringToInteger(const std::string& str);

int main(int argc, char** argv) {

    if (argc < 3) {

        std::cout << "Usage ./transmit <ID> " << std::endl;
        return 1;
    }

//     visor::CanFrame frame1;
// visor::CanFrame frame2(0x123, std::vector<uint8_t>{0x01, 0x02, 0x03});
// visor::CanFrame frame3(0x123, "data");
// visor::CanFrame frame4(0x123, data, size);

    visor::frameid_t id = 0;

    try {

        id = convertStringToInteger(std::string(argv[1]));
    }
    catch (std::invalid_argument& i) {

        std::cout << "Usage ./transmit <id> <text of size 8>" << std::endl;
        return 1;
    }

    if (strlen(argv[2]) > visor::MAX_FRAME_LENGTH) {

        std::cout << "Usage ./transmit <id> <text of size 8>" << std::endl;
        return 1;

    }

    std::string data(argv[2]);

    std::string interface("vcan0");

    visor::CanBus vcan(interface);

    if (!vcan.open()) {

        std::cerr << "Error opening CAN bus: " << vcan.errorString() << std::endl;
        return 1;
    }

    for (int i = 0; i < 10; ++i) {

        visor::CanFrame frame(id, data);

        std::cout << interface << " " << frame << " ( " << frame.stringData() << " )" << std::endl;

        if (!vcan.writeFrame(frame)) {

            std::cerr << "Error sending CAN frame: " << vcan.errorString() << std::endl;
            return 1;
        }
    }

    return 0;
}


int convertStringToInteger(const std::string& str) {

    if (str.empty()) {

        throw std::invalid_argument("stoi");
    }

    if (str.substr(0, 2) == "0x") {

        return std::stoi(str, nullptr, 16);
    } else {

        return std::stoi(str, nullptr, 10);
    }
}