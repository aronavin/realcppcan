cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CMAKE_FLAGS} -std=c++11")

set(PROJECT_NAME "visorcan")

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

include_directories("include")

add_library(${PROJECT_NAME} STATIC
        source/canbus.cpp
        source/canframe.cpp
)
