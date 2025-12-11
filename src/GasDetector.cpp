#include "../include/GasDetector.h"

GasDetector::GasDetector(const std::string& name, float sensitivity, float threshold)
    : Detector(name, DeviceType::GAS_DETECTOR, sensitivity, threshold),
      gasConcentration(0.0f) {
}

bool GasDetector::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }
    powerState = true;
    std::cout << "[GAS DETECTOR] " << name << " powered ON" << std::endl;
    return true;
}

bool GasDetector::powerOff() {
    // LLR17 - Critical devices cannot be powered off
    std::cout << "[ERROR] Cannot power off " << name << " - CRITICAL DEVICE!" << std::endl;
    return false;
}

std::string GasDetector::getStatus() const {
    std::string status = "GasDetector [" + name + "] (ID: " + std::to_string(id) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Sensitivity: " + std::to_string(sensitivity);
    status += " | Threshold: " + std::to_string(threshold);
    status += " | Gas Concentration: " + std::to_string(gasConcentration);
    return status;
}

bool GasDetector::detect() {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot detect - Device is OFF" << std::endl;
        return false;
    }
    
    if (gasConcentration > threshold * sensitivity) {
        std::cout << "🚨 [GAS DETECTED] " << name << " - Concentration: " 
                  << gasConcentration << " exceeds threshold!" << std::endl;
        return true;
    }
    return false;
}

Device* GasDetector::clone() const {
    // LLR15 - Prototype pattern
    return new GasDetector(name + "_copy", sensitivity, threshold);
}