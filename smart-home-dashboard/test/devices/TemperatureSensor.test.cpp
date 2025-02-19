#include <gtest/gtest.h>
#include <smart-home-dashboard/include/devices/TemperatureSensor.hpp>

class TemperatureSensorTest : public ::testing::Test {
protected:
    Temperature sensor{ "Bedroom Sensor", true, 22 };
};

TEST_F(TemperatureSensorTest, DefaultState) {
    EXPECT_EQ(sensor.getTemperature(), 22);
    EXPECT_TRUE(sensor.getStatus());
}

TEST_F(TemperatureSensorTest, SetAndGetTemperature) {
    sensor.setTemperature(25);
    EXPECT_EQ(sensor.getTemperature(), 25);
}

TEST_F(TemperatureSensorTest, ToggleSensor) {
    sensor.toggle();
    EXPECT_FALSE(sensor.getStatus());
}
