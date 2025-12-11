#include "../include/SmokeDetector.h"

SmokeDetector::SmokeDetector(const std::string& name, float sensitivity, float threshold)
    : Detector(name, DeviceType::SMOKE_DETECTOR, sensitivity, threshold),
      particleDensity(0.0f) {
}

bool SmokeDetector::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }
    powerState = true;
    std::cout << "[SMOKE DETECTOR] " << name << " powered ON" << std::endl;
    return true;
}

bool SmokeDetector::powerOff() {
    // LLR17 - Critical devices cannot be powered off
    std::cout << "[ERROR] Cannot power off " << name << " - CRITICAL DEVICE!" << std::endl;
    return false;
}

std::string SmokeDetector::getStatus() const {
    std::string status = "SmokeDetector [" + name + "] (ID: " + std::to_string(id) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Sensitivity: " + std::to_string(sensitivity);
    status += " | Threshold: " + std::to_string(threshold);
    status += " | Particle Density: " + std::to_string(particleDensity);
    return status;
}

bool SmokeDetector::detect() {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot detect - Device is OFF" << std::endl;
        return false;
    }
    
    if (particleDensity > threshold * sensitivity) {
        std::cout << "🚨 [SMOKE DETECTED] " << name << " - Density: " 
                  << particleDensity << " exceeds threshold!" << std::endl;
        return true;
    }
    return false;
}

Device* SmokeDetector::clone() const {
    // LLR15 - Prototype pattern
    return new SmokeDetector(name + "_copy", sensitivity, threshold);
}