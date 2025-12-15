#include "devices/GasDetectorDevice.h"
#include "devices/DetectorDevice.h"
#include <iostream>
#include <sstream>

static std::string toStrFloat(float v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

GasDetectorDevice::GasDetectorDevice(const std::string& name, float sensitivity, float threshold)
    : DetectorDevice(name, DeviceType::GAS_DETECTOR, sensitivity, threshold),
    gasConcentration(0.0f)
{
}

bool GasDetectorDevice::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON\n";
        return false;
    }
    powerState = true;
    std::cout << "[GAS DETECTOR] " << name << " powered ON\n";
    return true;
}

std::string GasDetectorDevice::getStatus() const {
    std::ostringstream oss;
    oss << "GasDetectorDevice [" << name << "] (ID: " << getId() << ")";
    oss << " - Status: " << (powerState ? "ON" : "OFF");
    oss << " | Sensitivity: " << toStrFloat(sensitivity);
    oss << " | Threshold: " << toStrFloat(threshold);
    oss << " | Gas Concentration: " << toStrFloat(gasConcentration);
    return oss.str();
}

bool GasDetectorDevice::detect() {
    if (!powerState) {
        std::cout << "[WARN] " << name << " is off and cannot detect\n";
        return false;
    }

    if (gasConcentration > threshold * sensitivity) {
        std::cout << "[CRITICAL] Gas threshold exceeded by " << name << "!\n";
        return true;
    }

    std::cout << "[DEBUG] " << name << " checked, condition normal\n";
    return false;
}

HomeDevice* GasDetectorDevice::clone() const {
    return new GasDetectorDevice(name + "_copy", sensitivity, threshold);
}
