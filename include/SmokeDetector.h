#pragma once
#include "Detector.h"

// Concrete Smoke Detector (LLR12)
class SmokeDetector : public Detector {
private:
    float particleDensity;
    
public:
    SmokeDetector(const std::string& name, float sensitivity = 0.7f, float threshold = 50.0f);
    
    // Override methods (LLR11)
    bool powerOn() override;
    bool powerOff() override; // LLR17 - Cannot power off critical devices
    std::string getStatus() const override;
    bool detect() override;
    Device* clone() const override; // LLR15
    
    // Specific methods
    void setParticleDensity(float density) { particleDensity = density; }
    float getParticleDensity() const { return particleDensity; }
};