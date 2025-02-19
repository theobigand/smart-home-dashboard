#include <smart-home-dashboard/include/devices/MotionSensor.hpp>

MotionSensor::MotionSensor(const string name, bool status): Device(name, status), motionDetected(false) {}

MotionSensor::~MotionSensor() {}


void MotionSensor::toggle() {
    status = !status;
}

// TODO: Redifine the << operator later on
void MotionSensor::print() {
    cout << "Motion Sensor: " << name << " (ID: " << id << ")" << endl;
    cout << "Status: " << (status ? "On" : "Off") << endl;
    cout << "MotionDetected: " << motionDetected << endl;
    cout << endl;
}

void MotionSensor::update() {
    // TODO: Generate random motion detection
}
