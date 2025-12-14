#include "Detector.h"

Detector::Detector(const std::string& name, DeviceType type, float sensitivity, float threshold)
    : Device(name, type, true),
      sensitivity(sensitivity), 
      threshold(threshold) {
    powerState = true;
    logger->log(LogLevel::INFO, "[DETECTOR CREATED] " + name + " - Sensitivity: " + std::to_string(sensitivity) + ", Threshold: " + std::to_string(threshold));
}

void Detector::setSensitivity(float sens) {
    if (sens >= 0.0f && sens <= 1.0f) {
        sensitivity = sens;
        logger->log(LogLevel::INFO, name + " sensitivity set to " + std::to_string(sens));
    } else {
        logger->log(LogLevel::WARNING, name + " invalid sensitivity value (must be 0-1)");
    }
}

void Detector::setThreshold(float thresh) {
    if (thresh >= 0.0f) {
        threshold = thresh;
        logger->log(LogLevel::INFO, name + " threshold set to " + std::to_string(thresh));
    } else {
        logger->log(LogLevel::WARNING, name + " invalid threshold value");
    }
}

bool Detector::detect() {
    if (!powerState) {
        logger->log(LogLevel::WARNING, name + " is off and cannot detect");
        return false;
    }

    if (checkCondition()) {
        notify();
        return true;
    }
    
    logger->log(LogLevel::DEBUG, name + " checked, condition normal");
    return false;
}

bool Detector::powerOff() {
    logger->log(LogLevel::CRITICAL, "SECURITY ALERT: Attempt to power off the Detector (" + name + ") was blocked");
    return false;
}

void Detector::notify() const {
    logger->log(LogLevel::CRITICAL, "CRITICAL DETECTION: Threshold exceeded by " + name + "!");
}