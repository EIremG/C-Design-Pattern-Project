#include "../include/Device.h"

// Static member initialization (LLR37)
int Device::nextID = 1000;

// Protected constructor (LLR9)
Device::Device(const std::string& name, DeviceType type, bool critical)
    : name(name), deviceType(type), isCritical(critical), powerState(false) {
    id = nextID++; // LLR37 - Auto-increment ID
    std::cout << "[DEVICE CREATED] " << name << " (ID: " << id << ")" << std::endl;
}

// Helper function
std::string Device::deviceTypeToString(DeviceType type) {
    switch(type) {
        case DeviceType::LIGHT: return "Light";
        case DeviceType::CAMERA: return "Camera";
        case DeviceType::TV: return "TV";
        case DeviceType::SMOKE_DETECTOR: return "Smoke Detector";
        case DeviceType::GAS_DETECTOR: return "Gas Detector";
        case DeviceType::ALARM: return "Alarm";
        case DeviceType::MUSIC_SYSTEM: return "Music System";
        default: return "Unknown";
    }
}