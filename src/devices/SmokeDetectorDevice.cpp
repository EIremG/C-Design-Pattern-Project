#include "devices/SmokeDetectorDevice.h"
#include <iostream>
#include <sstream>

static std::string toStrFloat(float v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

SmokeDetectorDevice::SmokeDetectorDevice(const std::string& name, float sensitivity, float threshold)
    : DetectorDevice(name, DeviceType::SMOKE_DETECTOR, sensitivity, threshold),
    particleDensity(0.0f)
{
}

bool SmokeDetectorDevice::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON\n";
        return false;
    }
    powerState = true;
    std::cout << "[SMOKE] " << name << " powered ON\n";
    return true;
}

std::string SmokeDetectorDevice::getStatus() const {
    std::ostringstream oss;
    oss << "SmokeDetectorDevice [" << name << "] (ID: " << getId() << ")";
    oss << " - Status: " << (powerState ? "ON" : "OFF");
    oss << " | Sensitivity: " << toStrFloat(sensitivity);
    oss << " | Threshold: " << toStrFloat(threshold);
    oss << " | Particle Density: " << toStrFloat(particleDensity);
    return oss.str();
}

bool SmokeDetectorDevice::detect() {
    if (!powerState) {
        std::cout << "[WARN] " << name << " is off and cannot detect\n";
        return false;
    }

    if (particleDensity > threshold * sensitivity) {
        std::cout << "[CRITICAL] Smoke threshold exceeded by " << name << "!\n";
        return true;
    }

    std::cout << "[DEBUG] " << name << " checked, condition normal\n";
    return false;
}

HomeDevice* SmokeDetectorDevice::clone() const {
    return new SmokeDetectorDevice(name + "_copy", sensitivity, threshold);
}
