#include "devices/LightDevice.h"
#include <iostream>
#include <sstream>

static std::string toStrInt(int v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

LightDevice::LightDevice(const std::string& name, const std::string& color, int illumination)
    : HomeDevice(name, DeviceType::LIGHT, false),
    color(color), illumination(illumination)
{
    if (this->illumination < 0) this->illumination = 0;
    if (this->illumination > 100) this->illumination = 100;
}

bool LightDevice::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON\n";
        return false;
    }

    powerState = true;
    std::cout << "[LIGHT] " << name << " turned ON - Color: " << color
        << ", Illumination: " << illumination << "%\n";
    return true;
}

bool LightDevice::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF\n";
        return false;
    }

    powerState = false;
    std::cout << "[LIGHT] " << name << " turned OFF\n";
    return true;
}

std::string LightDevice::getStatus() const {
    std::string status = "LightDevice [" + name + "] (ID: " + toStrInt(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Color: " + color;
    status += " | Illumination: " + toStrInt(illumination) + "%";
    return status;
}

void LightDevice::setColor(const std::string& newColor) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change color - Light is OFF\n";
        return;
    }

    color = newColor;
    std::cout << "[" << name << "] Color changed to " << color << "\n";
}

void LightDevice::setIllumination(int level) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change illumination - Light is OFF\n";
        return;
    }

    if (level < 0 || level > 100) {
        std::cout << "[" << name << "] Invalid illumination! Must be 0-100\n";
        return;
    }

    illumination = level;
    std::cout << "[" << name << "] Illumination set to " << illumination << "%\n";
}

HomeDevice* LightDevice::clone() const {
    return new LightDevice(name + "_copy", color, illumination);
}
