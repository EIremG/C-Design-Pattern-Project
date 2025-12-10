
#pragma once
#include "Device.h"

class Detector : public Device {
protected:
    float sensitivity;
    float threshold;

public:
    Detector(const std::string& name, DeviceType type);

    void powerOn() override;
    void powerOff() override;  // LLR17 - critical device

    virtual void detect() = 0;  // Her detector kendi algılama mantığına sahip

    void setSensitivity(float sens) { sensitivity = sens; }
    float getSensitivity() const { return sensitivity; }
    float getThreshold() const { return threshold; }
};