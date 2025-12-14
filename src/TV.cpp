#include "TV.h"

TV::TV(const std::string& name, TVBrand brand)
    : Device(name, DeviceType::TV, false),
      brand(brand), volume(30), channel(1) {
}

bool TV::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }
    
    powerState = true;
    std::cout << "📺 [TV] " << name << " powered ON - Model: " << brandToString(brand) << std::endl;
    std::cout << "   - Channel: " << channel << " | Volume: " << volume << "%" << std::endl;
    return true;
}

bool TV::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF" << std::endl;
        return false;
    }
    
    powerState = false;
    std::cout << "📺 [TV] " << name << " powered OFF" << std::endl;
    return true;
}

std::string TV::getStatus() const {
    std::string status = "TV [" + name + "] (ID: " + std::to_string(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Model: " + brandToString(brand);
    status += " | Channel: " + std::to_string(channel);
    status += " | Volume: " + std::to_string(volume) + "%";
    return status;
}

void TV::changeChannel(int newChannel) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change channel - TV is OFF" << std::endl;
        return;
    }
    
    if (newChannel < 1) {
        std::cout << "[" << name << "] Invalid channel!" << std::endl;
        return;
    }
    
    channel = newChannel;
    std::cout << "📺 [" << name << "] Channel changed to " << channel << std::endl;
}

void TV::setVolume(int vol) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change volume - TV is OFF" << std::endl;
        return;
    }
    
    if (vol < 0 || vol > 100) {
        std::cout << "[" << name << "] Invalid volume! Must be 0-100" << std::endl;
        return;
    }
    
    volume = vol;
    std::cout << "🔊 [" << name << "] Volume set to " << volume << "%" << std::endl;
}

std::string TV::brandToString(TVBrand brand) const {
    switch(brand) {
        case TVBrand::SAMSUNG: return "Samsung";
        case TVBrand::LG: return "LG";
        case TVBrand::SONY: return "Sony";
        default: return "Unknown";
    }
}

Device* TV::clone() const {
    TV* copy = new TV(name + "_copy", brand);
    copy->channel = this->channel;
    copy->volume = this->volume;
    return copy;
}