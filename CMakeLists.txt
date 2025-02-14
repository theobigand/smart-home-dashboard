# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(SmartHomeDashboard)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the deployment target
set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0")

# Find all the source files
file(GLOB SOURCES "src/*.cpp")

# Include the header files
include_directories(include)

# Find packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Add the executable
add_executable(SmartHomeDashboard main.cpp ${SOURCES})

# Link the libraries
target_link_libraries(SmartHomeDashboard PRIVATE Qt6::Widgets)