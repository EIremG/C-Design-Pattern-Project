#include "Light.h"

Light::Light(const std::string& name, const std::string& color, int illumination)
    : Device(name, DeviceType::LIGHT, false),
      color(color), illumination(illumination) {
    
    if (this->illumination < 0) this->illumination = 0;
    if (this->illumination > 100) this->illumination = 100;
}

bool Light::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }
    
    powerState = true;
    std::cout << "💡 [LIGHT] " << name << " turned ON - Color: " << color 
              << ", Illumination: " << illumination << "%" << std::endl;
    return true;
}

bool Light::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF" << std::endl;
        return false;
    }
    
    powerState = false;
    std::cout << "💡 [LIGHT] " << name << " turned OFF" << std::endl;
    return true;
}

std::string Light::getStatus() const {
    std::string status = "Light [" + name + "] (ID: " + std::to_string(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Color: " + color;
    status += " | Illumination: " + std::to_string(illumination) + "%";
    return status;
}

void Light::setColor(const std::string& newColor) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change color - Light is OFF" << std::endl;
        return;
    }
    
    color = newColor;
    std::cout << "🎨 [" << name << "] Color changed to " << color << std::endl;
}

void Light::setIllumination(int level) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change illumination - Light is OFF" << std::endl;
        return;
    }
    
    if (level < 0 || level > 100) {
        std::cout << "[" << name << "] Invalid illumination! Must be 0-100" << std::endl;
        return;
    }
    
    illumination = level;
    std::cout << "💡 [" << name << "] Illumination set to " << illumination << "%" << std::endl;
}

Device* Light::clone() const {
    return new Light(name + "_copy", color, illumination);
}