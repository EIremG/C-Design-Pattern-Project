#pragma once
#include "Device.h" 

class Light : public Device {
private:
    std::string color;
    int illumination; // 0-100%

public:
    Light(const std::string& name, const std::string& color, int illumination)
        : Device(name, DeviceType::LIGHT), color(color), illumination(illumination) {}

    // LLR15 - Prototype implementation (DÜZELTME: const eklendi)
    Device* clone() const override {
        return new Light(name, color, illumination);
    }

    // LLR17 - Criticality check (DÜZELTME: const eklendi)
    // 34. satırınız bu olmalı ve artık hata vermemeli.
    bool isCritical() const override { return false; } 

    // LLR35 - Specific operations
    void setColor(const std::string& newColor) {
        color = newColor;
        logger->log(LogLevel::INFO, getName() + " color set to " + color + ".");
    }

    void setIllumination(int level) {
        if (level >= 0 && level <= 100) {
            illumination = level;
            logger->log(LogLevel::INFO, getName() + " illumination set to " + std::to_string(illumination) + "%.");
        }
    }

    std::string getStatus() const override {
        return Device::getStatus() + " | Color: " + color + " | Illumination: " + std::to_string(illumination) + "%";
    }
};