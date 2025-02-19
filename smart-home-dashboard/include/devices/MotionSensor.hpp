#pragma once

#include <smart-home-dashboard/include/devices/Device.hpp>

class MotionSensor : public Device {
private:
    bool motionDetected;

public:
    MotionSensor(const string name, bool status);
    virtual ~MotionSensor();
    void toggle();
    void print();
    void update();
};