#include "devices/TVDevice.h"
#include <iostream>
#include <sstream>

static std::string toStrInt(int v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

TVDevice::TVDevice(const std::string& name, TVBrand brand)
    : HomeDevice(name, DeviceType::TV, false),
    brand(brand), volume(30), channel(1)
{
}

bool TVDevice::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON\n";
        return false;
    }

    powerState = true;
    std::cout << "[TV] " << name << " powered ON - Model: " << brandToString(brand) << "\n";
    std::cout << "   - Channel: " << channel << " | Volume: " << volume << "%\n";
    return true;
}

bool TVDevice::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF\n";
        return false;
    }

    powerState = false;
    std::cout << "[TV] " << name << " powered OFF\n";
    return true;
}

std::string TVDevice::getStatus() const {
    std::string status = "TVDevice [" + name + "] (ID: " + toStrInt(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Model: " + brandToString(brand);
    status += " | Channel: " + toStrInt(channel);
    status += " | Volume: " + toStrInt(volume) + "%";
    return status;
}

void TVDevice::changeChannel(int newChannel) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change channel - TV is OFF\n";
        return;
    }

    if (newChannel < 1) {
        std::cout << "[" << name << "] Invalid channel!\n";
        return;
    }

    channel = newChannel;
    std::cout << "[" << name << "] Channel changed to " << channel << "\n";
}

void TVDevice::setVolume(int vol) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot change volume - TV is OFF\n";
        return;
    }

    if (vol < 0 || vol > 100) {
        std::cout << "[" << name << "] Invalid volume! Must be 0-100\n";
        return;
    }

    volume = vol;
    std::cout << "[" << name << "] Volume set to " << volume << "%\n";
}

std::string TVDevice::brandToString(TVBrand b) const {
    switch (b) {
    case TVBrand::SAMSUNG: return "Samsung";
    case TVBrand::LG:      return "LG";
    case TVBrand::SONY:    return "Sony";
    default:               return "Unknown";
    }
}

HomeDevice* TVDevice::clone() const {
    TVDevice* copy = new TVDevice(name + "_copy", brand);
    copy->channel = this->channel;
    copy->volume = this->volume;
    return copy;
}
