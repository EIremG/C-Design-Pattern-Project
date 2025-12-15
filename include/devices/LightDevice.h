#pragma once
#include "devices/HomeDevice.h"

class LightDevice : public HomeDevice {
private:
    std::string color;
    int illumination;

public:
    LightDevice(const std::string& name, const std::string& color = "white", int illumination = 50);

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    HomeDevice* clone() const override;

    void setColor(const std::string& newColor);
    void setIllumination(int level);
};