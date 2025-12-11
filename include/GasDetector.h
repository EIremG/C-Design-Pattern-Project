#pragma once
#include "Detector.h"

// Concrete Gas Detector (LLR12)
class GasDetector : public Detector {
private:
    float gasConcentration;
    
public:
    GasDetector(const std::string& name, float sensitivity = 0.8f, float threshold = 100.0f);
    
    // Override methods
    bool powerOn() override;
    bool powerOff() override; // LLR17
    std::string getStatus() const override;
    bool detect() override;
    Device* clone() const override; // LLR15
    
    // Specific methods
    void setGasConcentration(float concentration) { gasConcentration = concentration; }
    float getGasConcentration() const { return gasConcentration; }
};