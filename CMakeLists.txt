# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(SmartHomeDashboard)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the deployment target
set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0")

# Find all the source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/smart-home-dashboard/*.cpp")

# Add the executable
add_executable(SmartHomeDashboard ${SOURCES})

# Add smart-home-dashboard/ as a system include directory
target_include_directories(SmartHomeDashboard SYSTEM PRIVATE "${CMAKE_SOURCE_DIR}")

# Find packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Link the libraries
target_link_libraries(SmartHomeDashboard PRIVATE Qt6::Widgets)