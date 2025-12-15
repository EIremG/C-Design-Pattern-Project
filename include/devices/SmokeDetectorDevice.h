#pragma once

#include "devices/DetectorDevice.h"
#include <string>

class SmokeDetectorDevice : public DetectorDevice {
private:
    float particleDensity;

public:
    SmokeDetectorDevice(const std::string& name,
        float sensitivity = 0.7f,
        float threshold = 50.0f);

    virtual bool powerOn();
    virtual std::string getStatus() const;
    virtual HomeDevice* clone() const;

    // DetectorDevice::detect() = 0 olduğu için zorunlu
    virtual bool detect();

    void setParticleDensity(float density) { particleDensity = density; }
    float getParticleDensity() const { return particleDensity; }
};
