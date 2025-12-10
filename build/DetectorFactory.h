#pragma once
#include "Detector.h"
#include "SmokeDetector.h"
#include "GasDetector.h"

enum class DetectorFactoryType {
    SMOKE,
    GAS
};

class DetectorFactory {
public:
    static Detector* createDetector(DetectorFactoryType type, const std::string& name = "");
};