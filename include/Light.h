#pragma once
#include "Device.h"

// Light device (LLR35)
class Light : public Device {
private:
    std::string color;
    int illumination; // 0-100
    
public:
    Light(const std::string& name, const std::string& color = "white", int illumination = 50);
    
    // Override methods (LLR11)
    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override; // LLR15
    
    // Specific methods (LLR35)
    void setColor(const std::string& newColor);
    void setIllumination(int level);
    std::string getColor() const { return color; }
    int getIllumination() const { return illumination; }
};