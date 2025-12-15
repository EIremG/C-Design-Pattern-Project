#include "devices/DetectorFactory.h"

DetectorDevice* DetectorFactory::createDetector(DetectorType type, const std::string& name, 
                                         float sensitivity, float threshold) {
    switch(type) {
        case DetectorType::SMOKE:
            std::cout << "[FACTORY] Creating Smoke Detector: " << name << std::endl;
            return new SmokeDetectorDevice(name, sensitivity, threshold);
            
        case DetectorType::GAS:
            std::cout << "[FACTORY] Creating Gas Detector: " << name << std::endl;
            return new GasDetectorDevice(name, sensitivity, threshold);
            
        default:
            std::cout << "[FACTORY ERROR] Unknown detector type!" << std::endl;
            return nullptr;
    }
}