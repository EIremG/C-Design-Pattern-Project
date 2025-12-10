#pragma once
#include "Detector.h"

class GasDetector : public Detector {
public:
    GasDetector(const std::string& name = "Gas Detector");
    void detect() override;
};