#pragma once
#include "Device.h"

class Detector : public Device {
protected:
    float sensitivity;
    float threshold;

    virtual bool checkCondition() const = 0;
    virtual void notify() const;

public:
    Detector(const std::string& name, DeviceType type, float sensitivity, float threshold);

    bool detect();
    bool powerOff() override;

    void setSensitivity(float sens);
    void setThreshold(float thresh);
    
    float getSensitivity() const { return sensitivity; }
    float getThreshold() const { return threshold; }
};