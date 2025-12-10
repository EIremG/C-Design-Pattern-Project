#include "GasDetector.h"
#include <iostream>

GasDetector::GasDetector(const std::string& name)
    : Detector(name, DeviceType::GAS_DETECTOR) {
}

void GasDetector::detect() {
    std::cout << "[DETECT] " << name << " scanning for gas leaks..." << std::endl;
}