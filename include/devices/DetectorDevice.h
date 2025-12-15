#pragma once

#include "devices/HomeDevice.h"
#include <string>

class DetectorDevice : public HomeDevice {
protected:
    float sensitivity;
    float threshold;

public:
    DetectorDevice(const std::string& name, DeviceType type, float sensitivity, float threshold);

    // Her detector kendi detect metodunu implement eder
    virtual bool detect() = 0;

    // Critical cihaz: kapanması engellenecek (LLR17 mantığı)
    virtual bool powerOff();

    // Setter methods
    void setSensitivity(float sens);
    void setThreshold(float thresh);

    // Getter methods
    float getSensitivity() const { return sensitivity; }
    float getThreshold() const { return threshold; }
};
