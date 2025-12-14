#pragma once
#include "Detector.h"

class GasDetector : public Detector {
private:
    float gasConcentration;

public:
    GasDetector(const std::string& name, float sensitivity = 0.7f, float threshold = 100.0f);

    bool powerOn() override;
    std::string getStatus() const override;
    Device* clone() const override;

    // Detector's pure virtual function
    bool detect() override;

    void setGasConcentration(float concentration) { gasConcentration = concentration; }
    float getGasConcentration() const { return gasConcentration; }
};
