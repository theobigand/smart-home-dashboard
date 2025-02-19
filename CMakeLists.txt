# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(SmartHomeDashboard)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the deployment target
set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0")

# Find all the source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/smart-home-dashboard/src/*.cpp")

# Add the executable
add_executable(SmartHomeDashboard "${CMAKE_SOURCE_DIR}/smart-home-dashboard/Main.cpp" ${SOURCES})

# Include directories
target_include_directories(SmartHomeDashboard PRIVATE ${CMAKE_SOURCE_DIR})

# Find packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Link the libraries
target_link_libraries(SmartHomeDashboard PRIVATE Qt6::Widgets)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB_RECURSE TEST_SOURCES "${CMAKE_SOURCE_DIR}/smart-home-dashboard/test/*.cpp")

add_executable(SmartHomeDashboardTests ${TEST_SOURCES} ${SOURCES})

target_include_directories(SmartHomeDashboardTests PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(SmartHomeDashboardTests GTest::GTest GTest::Main Qt6::Widgets)

gtest_discover_tests(SmartHomeDashboardTests)
add_test(NAME SmartHomeDashboardTests COMMAND SmartHomeDashboardTests)