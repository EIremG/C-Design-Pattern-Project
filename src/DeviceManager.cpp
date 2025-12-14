#include "DeviceManager.h"

DeviceManager* DeviceManager::instance = nullptr;

DeviceManager::DeviceManager() {
    std::cout << "[DEVICE MANAGER] Initialized" << std::endl;
}

DeviceManager* DeviceManager::getInstance() {
    if (instance == nullptr) {
        instance = new DeviceManager();
    }
    return instance;
}

void DeviceManager::addDevice(Device* device) {
    if (device == nullptr) {
        std::cout << "[MANAGER ERROR] Cannot add null device!" << std::endl;
        return;
    }
    
    devices.push_back(device);
    std::cout << "[MANAGER] Device added: " << device->getName() 
              << " (ID: " << device->getId() << ")" << std::endl;
}

bool DeviceManager::removeDevice(int deviceId) {
    for (auto it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getId() == deviceId) {
            if ((*it)->isCriticalDevice()) {
                std::cout << "[MANAGER ERROR] Cannot remove critical device: " 
                          << (*it)->getName() << std::endl;
                return false;
            }
            
            std::cout << "[MANAGER] Device removed: " << (*it)->getName() 
                      << " (ID: " << deviceId << ")" << std::endl;
            delete *it;
            devices.erase(it);
            return true;
        }
    }
    
    std::cout << "[MANAGER ERROR] Device with ID " << deviceId << " not found!" << std::endl;
    return false;
}

Device* DeviceManager::getDeviceById(int id) const {
    for (Device* device : devices) {
        if (device->getId() == id) {
            return device;
        }
    }
    return nullptr;
}

void DeviceManager::listAllDevices() const {
    if (devices.empty()) {
        std::cout << "\n[DEVICE LIST] No devices registered\n" << std::endl;
        return;
    }
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "         DEVICE LIST (LLR32)" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Total Devices: " << devices.size() << "\n" << std::endl;
    
    for (const Device* device : devices) {
        std::cout << "ID: " << device->getId() 
                  << " | Name: " << device->getName()
                  << " | Status: " << (device->getPowerState() ? "ON " : "OFF")
                  << " | Type: " << Device::deviceTypeToString(device->getDeviceType())
                  << (device->isCriticalDevice() ? " [CRITICAL]" : "")
                  << std::endl;
    }
    std::cout << "========================================\n" << std::endl;
}

void DeviceManager::listDevicesByType(DeviceType type) const {
    std::cout << "\n[DEVICES OF TYPE: " << Device::deviceTypeToString(type) << "]" << std::endl;
    
    bool found = false;
    for (const Device* device : devices) {
        if (device->getDeviceType() == type) {
            std::cout << device->getStatus() << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No devices of this type found." << std::endl;
    }
    std::cout << std::endl;
}

DeviceManager::~DeviceManager() {
    std::cout << "[DEVICE MANAGER] Cleaning up..." << std::endl;
    for (Device* device : devices) {
        delete device;
    }
    devices.clear();
}