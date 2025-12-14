#include "Device.h"

int Device::nextID = 1000;

Device::Device(const std::string& name, DeviceType type, bool critical)
    : name(name), deviceType(type), isCritical(critical), powerState(false) {
    id = nextID++;
    logger = Logger::getInstance();
    logger->log(LogLevel::INFO, "[DEVICE CREATED] " + name + " (ID: " + std::to_string(id) + ")");
}

Device::~Device() {
    logger->log(LogLevel::INFO, "[DEVICE DESTROYED] " + name);
}

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