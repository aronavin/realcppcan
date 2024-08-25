#include <thread>
#include <chrono>
#include <random>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#include "../include/visorcan.h"

std::vector<uint8_t> generateRandomVector();
int convertStringToInteger(const std::string& str);
void printTimeStamp();

int main(int argc, char** argv) {

    if (argc < 2) {

        std::cout << "Usage ./transmit <ID> " << std::endl;
        return 1;
    }

    visor::frameid_t id = 0;

    try {

        id = convertStringToInteger(std::string(argv[1]));
    }
    catch (std::invalid_argument& i) {

        std::cout << "Usage ./transmit <id> " << std::endl;
        return 1;
    }

    std::string interface("vcan0");

    visor::CanBus vcan(interface);

    if (!vcan.open()) {

        std::cerr << "Error opening CAN bus: " << vcan.errorString() << std::endl;
        return 1;
    }

    uint64_t counter = 0;
    
    auto start_time = std::chrono::steady_clock::now();

    int timestamp = 0;

    while (true)
    {
        auto now = std::chrono::steady_clock::now();

        auto elapsed_minutes = std::chrono::duration_cast<std::chrono::minutes>(now - start_time).count();
        auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(now - start_time - std::chrono::minutes(elapsed_minutes)).count();

        if (elapsed_minutes >= 1) {

            break;
        }
        
        try {
            
            visor::CanFrame frame(id, generateRandomVector());
            
            printf("%ld) ", counter + 1);

            printf("Time: %02ld:%02ld ", elapsed_minutes, elapsed_seconds);

            std::cout << interface << " " << frame << std::endl;

            if (!vcan.writeFrame(frame)) {

                std::cerr << "Error sending CAN frame: " << vcan.errorString() << std::endl;
                continue;
            }
        }
        catch (std::length_error& e) {

            std::cerr << e.what() << std::endl;
        }

        counter++;

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}

std::vector<uint8_t> generateRandomVector() {

    int max_size = 8;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> size_dist(1, max_size);
    std::uniform_int_distribution<uint8_t> value_dist(0, 255);

    int size = size_dist(gen);

    std::vector<uint8_t> data(size);

    for (size_t i = 0; i < size; ++i) {

        data[i] = value_dist(gen);
    }

    return data;
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