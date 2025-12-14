#include "SmokeDetector.h"

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

std::string SmokeDetector::getStatus() const {
    std::string status = "SmokeDetector [" + name + "] (ID: " + std::to_string(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Sensitivity: " + std::to_string(sensitivity);
    status += " | Threshold: " + std::to_string(threshold);
    status += " | Particle Density: " + std::to_string(particleDensity);
    return status;
}

bool SmokeDetector::checkCondition() const {
    return particleDensity > threshold * sensitivity;
}

Device* SmokeDetector::clone() const {
    return new SmokeDetector(name + "_copy", sensitivity, threshold);
}