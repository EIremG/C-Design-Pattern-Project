#pragma once
#include "SmokeDetector.h"
#include "GasDetector.h"

enum class DetectorType {
    SMOKE,
    GAS
};

// Factory Method Pattern (LLR12)
// Single Responsibility: Only creates detectors
class DetectorFactory {
public:
    static Detector* createDetector(DetectorType type, const std::string& name, 
                                    float sensitivity = 0.7f, float threshold = 50.0f);
private:
    DetectorFactory() = delete; // Prevent instantiation
};