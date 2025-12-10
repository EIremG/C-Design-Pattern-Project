#include "DetectorFactory.h"

Detector* DetectorFactory::createDetector(DetectorFactoryType type, const std::string& name) {
    switch (type) {
    case DetectorFactoryType::SMOKE:
        return name.empty() ? new SmokeDetector() : new SmokeDetector(name);
    case DetectorFactoryType::GAS:
        return name.empty() ? new GasDetector() : new GasDetector(name);
    default:
        return nullptr;
    }
}