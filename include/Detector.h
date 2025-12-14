#pragma once
#include "Device.h"

class Detector : public Device {
protected:
    float sensitivity;
    float threshold;

public:
    Detector(const std::string& name, DeviceType type, float sensitivity, float threshold);

    // Virtual methods for subclasses
    virtual bool detect() = 0;  // Her detector kendi detect metodunu implement eder
    
    bool powerOff() override;

    // Setter methods
    void setSensitivity(float sens);
    void setThreshold(float thresh);
    
    // Getter methods
    float getSensitivity() const { return sensitivity; }
    float getThreshold() const { return threshold; }
};
