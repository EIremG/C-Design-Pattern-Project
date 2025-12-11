#pragma once
#include "Device.h"

// Abstract Detector class (LLR12)
class Detector : public Device {
protected:
    float sensitivity;
    float threshold;
    
    // Protected constructor
    Detector(const std::string& name, DeviceType type, float sensitivity, float threshold);
    
public:
    virtual ~Detector() = default;
    
    // Pure virtual method - Interface Segregation Principle
    virtual bool detect() = 0;
    
    // Getters
    float getSensitivity() const { return sensitivity; }
    float getThreshold() const { return threshold; }
    
    // Setters with validation
    void setSensitivity(float sens);
    void setThreshold(float thresh);
};