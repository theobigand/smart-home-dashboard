#include <smart-home-dashboard/include/core/SmartHomeManager.hpp>

int SmartHomeManager::generateUniqueID() {
    static int nextID = 1;
    while (deviceIDs.find(nextID) != deviceIDs.end()) {
        nextID++;
    }
    deviceIDs.insert(nextID);
    return nextID;
}


SmartHomeManager::~SmartHomeManager() {
    for (Device* device : devices) {
        delete device;
    }
}

void SmartHomeManager::addDevice(Device* device) {
    int id = generateUniqueID();
    device->setID(id);
    devices.insert(device);
}

void SmartHomeManager::removeDevice(int id) {
    Device* device = getDevice(id);
    if (device != nullptr) {
        devices.erase(device);
        deviceIDs.erase(id);
        delete device;
    }
}

void SmartHomeManager::toggleDevice(int id) {
    Device* device = getDevice(id);
    if (device != nullptr) {
        device->toggle();
    }
}

void SmartHomeManager::printDevices() {
    for (Device* device : devices) {
        device->print();
    }
}

void SmartHomeManager::updateDevices() {
    for (Device* device : devices) {
        device->update();
    }
}


Device* SmartHomeManager::getDevice(int id) {
    for (Device* device : devices) {
        if (device->getID() == id) {
            return device;
        }
    }
    return nullptr;
}

int SmartHomeManager::getDeviceID(Device* device) {
    return device->getID(); // Fetch from database (later)
}

unordered_set<Device*> SmartHomeManager::getDevices() {
    return devices;
}