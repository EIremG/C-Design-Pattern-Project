#include "../include/TV.h"

TV::TV(const std::string& name, TVModel model)
    : Device(name, DeviceType::TV, false), // Not critical
      model(model), channel(1), volume(30) {
}

bool TV::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }
    
    powerState = true;
    std::cout << "📺 [TV] " << name << " powered ON - Model: " << modelToString(model) << std::endl;
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
    std::string status = "TV [" + name + "] (ID: " + std::to_string(id) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Model: " + modelToString(model);
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

std::string TV::modelToString(TVModel model) {
    switch(model) {
        case TVModel::SAMSUNG: return "Samsung";
        case TVModel::LG: return "LG";
        case TVModel::SONY: return "Sony";
        default: return "Unknown";
    }
}

Device* TV::clone() const {
    // LLR15 - Prototype pattern
    TV* copy = new TV(name + "_copy", model);
    copy->channel = this->channel;
    copy->volume = this->volume;
    return copy;
}