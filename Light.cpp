#include "Light.h"
#include <iostream>

Light::Light(int id, const std::string& name)
    : Device(id, name, "Light"), color("white"), illumination(100) {}

void Light::setColor(const std::string& c) { color = c; }
void Light::setIllumination(int i) { illumination = i; }

void Light::powerOn() { powerState = true; }
void Light::powerOff() { powerState = false; }

void Light::printDetails() const {
    std::cout << "   Color: " << color
              << " | Illumination: " << illumination << "\n";
}
