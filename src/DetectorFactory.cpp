#include "../include/DetectorFactory.h"

Detector* DetectorFactory::createDetector(DetectorType type, const std::string& name, 
                                         float sensitivity, float threshold) {
    switch(type) {
        case DetectorType::SMOKE:
            std::cout << "[FACTORY] Creating Smoke Detector: " << name << std::endl;
            return new SmokeDetector(name, sensitivity, threshold);
            
        case DetectorType::GAS:
            std::cout << "[FACTORY] Creating Gas Detector: " << name << std::endl;
            return new GasDetector(name, sensitivity, threshold);
            
        default:
            std::cout << "[FACTORY ERROR] Unknown detector type!" << std::endl;
            return nullptr;
    }
}