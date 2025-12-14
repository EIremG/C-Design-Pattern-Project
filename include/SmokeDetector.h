#pragma once
#include "Detector.h"

class SmokeDetector : public Detector {
private:
    float particleDensity;

public:
    SmokeDetector(const std::string& name, float sensitivity = 0.7f, float threshold = 50.0f);

    bool powerOn() override;
    std::string getStatus() const override;
    Device* clone() const override;

    // Detector's pure virtual function
    bool detect() override;

    void setParticleDensity(float density) { particleDensity = density; }
    float getParticleDensity() const { return particleDensity; }
};
