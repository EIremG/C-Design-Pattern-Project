#include "sim/Device.h"

// LLR10: Device sinifi implementasyonu
Device::Device(int id, const std::string& deviceName)
    : deviceId(id), name(deviceName), status("OFF") {
}

Device::~Device() {
}

std::string Device::getStatus() const {
    return status;
}

int Device::getId() const {
    return deviceId;
}

std::string Device::getName() const {
    return name;
}

void Device::setFailed() {
    status = "FAILED";
}
