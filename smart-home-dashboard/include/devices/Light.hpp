#pragma once

#include <smart-home-dashboard/include/devices/Device.hpp>

class Light : public Device {
private:
    // The light's brightness
    int brightness;
    bool isON;

public:
    Light(const string name, bool status, int brightness);
    virtual ~Light();
    int getBrightness();
    void setBrightness(int brightness);
    void toggle() override;
    void print() override;
    void update() override {}; // Light does not need to update
};