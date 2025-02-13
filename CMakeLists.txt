# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(SmartHomeAutomation)

set(CMAKE_CXX_STANDARD 17)

# Find all the files in the src directory
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Add the executable
add_executable(SmartHomeAutomation ${SOURCES} ${HEADERS})