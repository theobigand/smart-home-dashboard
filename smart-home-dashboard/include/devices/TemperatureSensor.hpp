#pragma once

#include <smart-home-dashboard/include/devices/Device.hpp>


class Temperature: public Device {
private:
    // The temperature sensor's temperature
    float temperature;

public:
    Temperature(const string name, bool status, int temperature);
    virtual ~Temperature();
    int getTemperature();
    void setTemperature(int temperature);
    void toggle();
    void print();
    void update();
};