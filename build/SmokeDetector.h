
#pragma once
#include "Detector.h"

class SmokeDetector : public Detector {
public:
    SmokeDetector(const std::string& name = "Smoke Detector");
    void detect() override;
};