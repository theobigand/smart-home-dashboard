#include <gtest/gtest.h>
#include <smart-home-dashboard/include/devices/MotionSensor.hpp>

class MotionSensorTest : public ::testing::Test {
protected:
    MotionSensor sensor{ "Front Door Motion", false };
};

TEST_F(MotionSensorTest, DefaultState) {
    EXPECT_FALSE(sensor.getStatus());
}

TEST_F(MotionSensorTest, ToggleSensor) {
    sensor.toggle();
    EXPECT_TRUE(sensor.getStatus());

    sensor.toggle();
    EXPECT_FALSE(sensor.getStatus());
}
