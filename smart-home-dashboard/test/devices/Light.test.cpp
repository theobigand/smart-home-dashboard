#include <gtest/gtest.h>
#include <smart-home-dashboard/include/devices/Light.hpp>

class LightTest : public ::testing::Test {
protected:
    Light light{ "Living Room Light", false, 50 };
};

TEST_F(LightTest, DefaultState) {
    EXPECT_EQ(light.getBrightness(), 50);
    EXPECT_FALSE(light.getStatus());
}

TEST_F(LightTest, ToggleLight) {
    light.toggle();
    EXPECT_TRUE(light.getStatus());

    light.toggle();
    EXPECT_FALSE(light.getStatus());
}

TEST_F(LightTest, SetAndGetBrightness) {
    light.setBrightness(80);
    EXPECT_EQ(light.getBrightness(), 80);
}
