#include <smart-home-dashboard/include/devices/Light.hpp>

Light::Light(const string name, bool status, int brightness) : Device(name, status), brightness(brightness), isON(status) {}

Light::~Light() {}

int Light::getBrightness() {
    return brightness;
}

void Light::setBrightness(int brightness) {
    this->brightness = brightness;
}

void Light::toggle() {
    status = !status;
    isON = status;
}

// TODO: Redifine the << operator later on
void Light::print() {
    cout << "Light: " << name << " (ID: " << id << ")" << endl;
    cout << "isON: " << (status ? "Yes" : "No") << endl;
    cout << "Brightness: " << brightness << endl;
    cout << endl;
}
