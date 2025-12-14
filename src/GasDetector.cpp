#include "GasDetector.h"

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

std::string GasDetector::getStatus() const {
    std::string status = "GasDetector [" + name + "] (ID: " + std::to_string(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Sensitivity: " + std::to_string(sensitivity);
    status += " | Threshold: " + std::to_string(threshold);
    status += " | Gas Concentration: " + std::to_string(gasConcentration);
    return status;
}

bool GasDetector::detect() {
    if (!powerState) {
        logger->log(LogLevel::WARNING, name + " is off and cannot detect");
        return false;
    }
    
    if (gasConcentration > threshold * sensitivity) {
        logger->log(LogLevel::CRITICAL, "CRITICAL DETECTION: Gas threshold exceeded by " + name + "!");
        return true;
    }
    
    logger->log(LogLevel::DEBUG, name + " checked, condition normal");
    return false;
}

Device* GasDetector::clone() const {
    return new GasDetector(name + "_copy", sensitivity, threshold);
}
