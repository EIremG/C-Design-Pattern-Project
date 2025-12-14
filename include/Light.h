#pragma once
#include "Device.h" 

class Light : public Device {
private:
    std::string color;
    int illumination;

public:
    Light(const std::string& name, const std::string& color = "white", int illumination = 50);

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override;

    void setColor(const std::string& newColor);
    void setIllumination(int level);
};