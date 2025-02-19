#pragma once

#include <iostream>
#include <string>

using namespace std;

class Device {
protected:
    // The device's name
    string name;

    // The device's unique identifier
    int id;

    // The device's status (on/off)
    bool status;

public:
    Device(const string name, bool status);
    virtual ~Device();
    string getName();
    int getID();
    void setID(int id);
    bool getStatus();
    void setStatus(bool status);
    virtual void toggle() = 0;
    virtual void print() = 0;
    virtual void update() = 0;
};