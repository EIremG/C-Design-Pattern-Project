#include "devices/DetectorDevice.h"
#include <iostream>
#include <sstream>

static std::string toStrFloat(float v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

DetectorDevice::DetectorDevice(const std::string& name, DeviceType type, float sensitivity, float threshold)
    : HomeDevice(name, type, true),
    sensitivity(sensitivity),
    threshold(threshold)
{
    powerState = true;
    std::cout << "[DETECTOR CREATED] " << this->name
        << " - Sensitivity: " << toStrFloat(this->sensitivity)
        << ", Threshold: " << toStrFloat(this->threshold) << std::endl;
}

void DetectorDevice::setSensitivity(float sens) {
    if (sens >= 0.0f && sens <= 1.0f) {
        sensitivity = sens;
        std::cout << "[" << name << "] sensitivity set to " << toStrFloat(sens) << std::endl;
    }
    else {
        std::cout << "[" << name << "] invalid sensitivity value (must be 0-1)" << std::endl;
    }
}

void DetectorDevice::setThreshold(float thresh) {
    if (thresh >= 0.0f) {
        threshold = thresh;
        std::cout << "[" << name << "] threshold set to " << toStrFloat(thresh) << std::endl;
    }
    else {
        std::cout << "[" << name << "] invalid threshold value" << std::endl;
    }
}

bool DetectorDevice::powerOff() {
    std::cout << "[CRITICAL] Attempt to power off DetectorDevice (" << name << ") was blocked" << std::endl;
    return false;
}
