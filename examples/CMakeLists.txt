cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME "Example programs")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CMAKE_FLAGS} -std=c++11 -pthread")

set(VISORCAN_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/../build/libvisorcan.a)

add_executable(receive receive.cpp)
target_link_libraries(receive ${VISORCAN_LIBRARY})

add_executable(transmit transmit.cpp)
target_link_libraries(transmit ${VISORCAN_LIBRARY})

add_executable(async_receive async_receive.cpp)
target_link_libraries(async_receive ${VISORCAN_LIBRARY})

add_executable(transmit_string transmit_string.cpp)
target_link_libraries(transmit_string ${VISORCAN_LIBRARY})

