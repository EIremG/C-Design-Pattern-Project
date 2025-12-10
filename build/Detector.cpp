#include "Detector.h"
#include <iostream>

Detector::Detector(const std::string& name, DeviceType type)
    : Device(name, type, true),  // LLR17 - detectors are CRITICAL
    sensitivity(0.5f), threshold(0.7f) {
}

void Detector::powerOn() {
    status = DeviceStatus::ACTIVE;
    std::cout << "[LOG] " << name << " powered ON (Critical Device)" << std::endl;
}

void Detector::powerOff() {
    // LLR17 - Critical devices cannot be powered off
    std::cout << "[ERROR] Cannot power off critical device: " << name << std::endl;
    std::cout << "[INFO] Critical devices (detectors, alarm) must remain active for safety." << std::endl;
}