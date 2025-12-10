#include "SmokeDetector.h"
#include <iostream>

SmokeDetector::SmokeDetector(const std::string& name)
    : Detector(name, DeviceType::SMOKE_DETECTOR) {
}

void SmokeDetector::detect() {
    std::cout << "[DETECT] " << name << " scanning for smoke..." << std::endl;
}