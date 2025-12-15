#pragma once
#include "devices/DetectorDevice.h"
#include "devices/SmokeDetectorDevice.h"
#include "devices/GasDetectorDevice.h"

enum class DetectorType {
    SMOKE,
    GAS
};

class DetectorFactory {
public:
    static DetectorDevice* createDetector(DetectorType type, const std::string& name, 
                                    float sensitivity = 0.7f, float threshold = 50.0f);
};