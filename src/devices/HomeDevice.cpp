#include "devices/HomeDevice.h"
#include <iostream>
#include <sstream>

int HomeDevice::nextID = 1000;

static std::string toStrInt(int v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

HomeDevice::HomeDevice(const std::string& name, DeviceType type, bool critical)
    : name(name),
    deviceType(type),
    isCritical(critical),
    powerState(false)
{
    id = nextID++;
    std::cout << "[DEVICE CREATED] " << name << " (ID: " << toStrInt(id) << ")\n";
}

HomeDevice::~HomeDevice() {
    std::cout << "[DEVICE DESTROYED] " << name << " (ID: " << toStrInt(id) << ")\n";
}

std::string HomeDevice::deviceTypeToString(DeviceType type) {
    switch (type) {
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
