#include "Device.h"
#include <iostream>
#include "Logger.h"

// ID generator başlangıcı
int Device::nextID = 1000;

Device::Device(const std::string& name, DeviceType type, bool isCritical)
    : name(name), deviceType(type), isCriticalDeviceFlag(isCritical), powerState(false)
{
    id = nextID++; // otomatik ID ataması
    Logger::getInstance().log(LogLevel::INFO, "Device created: " + name + " (ID: " + std::to_string(id) + ")");
}

void Device::powerOn() {
    powerState = true;
    Logger::getInstance().log(LogLevel::INFO, "Device powered ON: " + name + " (ID: " + std::to_string(id) + ")");
    std::cout << "Device [" << name << "] (ID: " << id << ") is now ON.\n";
}

bool Device::powerOff() {
    if (isCriticalDeviceFlag) {
        std::cout << "ERROR: Cannot power off critical device [" << name << "]!\n";
        Logger::getInstance().log(LogLevel::WARNING, "Attempted to power off critical device: " + name);
        return false;
    }
    powerState = false;
    Logger::getInstance().log(LogLevel::INFO, "Device powered OFF: " + name + " (ID: " + std::to_string(id) + ")");
    std::cout << "Device [" << name << "] (ID: " << id << ") is now OFF.\n";
    return true;
}
