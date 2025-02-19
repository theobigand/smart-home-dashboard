#pragma once

#include <unordered_set>
#include <smart-home-dashboard/include/devices/Device.hpp>

class SmartHomeManager {
private:
    // The list of devices
    unordered_set<Device*> devices;
    unordered_set<int> deviceIDs;
    int generateUniqueID(); // Generate a unique ID for a device, Query database for max ID (later)

public:
    SmartHomeManager(){};
    virtual ~SmartHomeManager();
    void addDevice(Device* device);
    void removeDevice(int id);
    void toggleDevice(int id);
    void printDevices();
    void updateDevices();
    Device* getDevice(int id);
    int getDeviceID(Device* device); // Fetch from database (later)
    unordered_set<Device*> getDevices();
};