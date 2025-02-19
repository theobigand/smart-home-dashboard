#include <smart-home-dashboard/include/devices/TemperatureSensor.hpp>

Temperature::Temperature(const string name, bool status, int temperature) : Device(name, status), temperature(temperature) {}

Temperature::~Temperature() {}

int Temperature::getTemperature() {
    return temperature;
}

void Temperature::setTemperature(int temperature) {
    this->temperature = temperature;
}

void Temperature::toggle() {
    status = !status;
}

// TODO: Redifine the << operator later on
void Temperature::print() {
    cout << "Temperature Sensor: " << name << " (ID: " << id << ")" << endl;
    cout << "Status: " << (status ? "On" : "Off") << endl;
    cout << "Temperature: " << temperature << endl;
    cout << endl;
}

void Temperature::update() {
    // TODO: Generate random temperature
}
