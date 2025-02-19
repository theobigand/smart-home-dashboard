#include <smart-home-dashboard/include/devices/Device.hpp>

Device::Device(const string name, bool status): name(name), status(status) {}

Device::~Device() {}

string Device::getName() {
    return name;
}

int Device::getID() {
    return id;
}

void Device::setID(int id) {
    this->id = id;
}

bool Device::getStatus() {
    return status;
}

void Device::setStatus(bool status) {
    this->status = status;
}
