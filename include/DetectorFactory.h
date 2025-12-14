#pragma once
#include "Detector.h"
#include "SmokeDetector.h"
#include "GasDetector.h"

enum class DetectorType {
    SMOKE,
    GAS
};

class DetectorFactory {
public:
    static Detector* createDetector(DetectorType type, const std::string& name, 
                                    float sensitivity = 0.7f, float threshold = 50.0f);
};