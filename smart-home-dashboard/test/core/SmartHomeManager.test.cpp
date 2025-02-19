#include <gtest/gtest.h>
#include <smart-home-dashboard/include/core/SmartHomeManager.hpp>
#include <smart-home-dashboard/include/devices/Light.hpp>
#include <smart-home-dashboard/include/devices/MotionSensor.hpp>
#include <smart-home-dashboard/include/devices/TemperatureSensor.hpp>

class SmartHomeManagerTest : public ::testing::Test {
protected:
    SmartHomeManager manager;
};

// ✅ Test Adding Multiple Devices
TEST_F(SmartHomeManagerTest, AddMultipleDevices) {
    Light* light = new Light("Living Room Light", false, 60);
    MotionSensor* motionSensor = new MotionSensor("Front Door Sensor", false);
    Temperature* tempSensor = new Temperature("Bedroom Sensor", true, 22);

    manager.addDevice(light);
    manager.addDevice(motionSensor);
    manager.addDevice(tempSensor);

    EXPECT_EQ(manager.getDeviceID(light), light->getID());
    EXPECT_EQ(manager.getDeviceID(motionSensor), motionSensor->getID());
    EXPECT_EQ(manager.getDeviceID(tempSensor), tempSensor->getID());
}

// ✅ Test Removing a Device
TEST_F(SmartHomeManagerTest, RemoveDevice) {
    Light* light = new Light("Hallway Light", false, 40);
    manager.addDevice(light);
    int id = light->getID();

    manager.removeDevice(id);
    EXPECT_EQ(manager.getDevice(id), nullptr);
}

// ✅ Test Toggling Different Device Types
TEST_F(SmartHomeManagerTest, ToggleMultipleDevices) {
    Light* light = new Light("Kitchen Light", false, 70);
    MotionSensor* motionSensor = new MotionSensor("Garage Motion", false);
    Temperature* tempSensor = new Temperature("Office Sensor", true, 24);

    manager.addDevice(light);
    manager.addDevice(motionSensor);
    manager.addDevice(tempSensor);

    int lightID = light->getID();
    int motionID = motionSensor->getID();
    int tempID = tempSensor->getID();

    // Toggle all devices
    manager.toggleDevice(lightID);
    manager.toggleDevice(motionID);
    manager.toggleDevice(tempID);

    EXPECT_TRUE(light->getStatus());
    EXPECT_TRUE(motionSensor->getStatus());
    EXPECT_FALSE(tempSensor->getStatus()); // It was initially ON, toggling should turn it OFF
}

// ✅ Test Retrieving All Devices
TEST_F(SmartHomeManagerTest, RetrieveAllDevices) {
    Light* light = new Light("Living Room Light", false, 60);
    MotionSensor* motionSensor = new MotionSensor("Front Door Sensor", false);
    Temperature* tempSensor = new Temperature("Bedroom Sensor", true, 22);

    manager.addDevice(light);
    manager.addDevice(motionSensor);
    manager.addDevice(tempSensor);

    auto devices = manager.getDevices();
    EXPECT_EQ(devices.size(), 3);
}

// ✅ Test Unique IDs for Multiple Devices
TEST_F(SmartHomeManagerTest, UniqueDeviceIDs) {
    Light* light1 = new Light("Light 1", false, 50);
    Light* light2 = new Light("Light 2", false, 70);
    MotionSensor* sensor1 = new MotionSensor("Motion 1", false);

    manager.addDevice(light1);
    manager.addDevice(light2);
    manager.addDevice(sensor1);

    EXPECT_NE(light1->getID(), light2->getID());
    EXPECT_NE(light1->getID(), sensor1->getID());
    EXPECT_NE(light2->getID(), sensor1->getID());
}
