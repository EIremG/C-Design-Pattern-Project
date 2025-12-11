#include "../include/Detector.h"

Detector::Detector(const std::string& name, DeviceType type, float sensitivity, float threshold)
    : Device(name, type, true), // All detectors are critical (LLR17)
      sensitivity(sensitivity), 
      threshold(threshold) {
    powerState = true; // Detectors always ON by default
    std::cout << "[DETECTOR CREATED] " << name << " - Sensitivity: " << sensitivity 
              << ", Threshold: " << threshold << std::endl;
}

void Detector::setSensitivity(float sens) {
    if (sens >= 0.0f && sens <= 1.0f) {
        sensitivity = sens;
        std::cout << "[" << name << "] Sensitivity set to " << sens << std::endl;
    } else {
        std::cout << "[" << name << "] Invalid sensitivity value (must be 0-1)" << std::endl;
    }
}

void Detector::setThreshold(float thresh) {
    if (thresh >= 0.0f) {
        threshold = thresh;
        std::cout << "[" << name << "] Threshold set to " << thresh << std::endl;
    } else {
        std::cout << "[" << name << "] Invalid threshold value" << std::endl;
    }
}