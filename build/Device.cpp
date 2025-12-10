#include "Device.h"
#include "DeviceIdGenerator.h"
#include <iostream>

Device::Device(const std::string& name, DeviceType type, bool critical)
    : name(name), deviceType(type), isCritical(critical), status(DeviceStatus::INACTIVE) {
    // LLR37 - Auto ID generation
    id = DeviceIdGenerator::getInstance()->getNextId();
    std::cout << "[LOG] Device created: ID=" << id << ", Name=" << name << std::endl;
}

std::string Device::getStatus() const {
    std::string statusStr;
    switch (status) {
    case DeviceStatus::ACTIVE:
        statusStr = "ON";
        break;
    case DeviceStatus::INACTIVE:
        statusStr = "OFF";
        break;
    case DeviceStatus::FAILED:
        statusStr = "FAILED";
        break;
    }
    return "ID: " + std::to_string(id) + " | " + name + " | Status: " + statusStr;
}