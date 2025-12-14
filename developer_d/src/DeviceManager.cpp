#include "DeviceManager.h"
#include <iostream>

// Singleton Pattern - static instance
DeviceManager* DeviceManager::instance = NULL;

// Singleton Pattern
DeviceManager::DeviceManager() {
}

DeviceManager::~DeviceManager() {
    // Tum cihazlari temizle
    std::map<int, Device*>::iterator it;
    for (it = devices.begin(); it != devices.end(); ++it) {
        delete it->second;
    }
    devices.clear();
}

DeviceManager& DeviceManager::getInstance() {
    if (instance == NULL) {
        instance = new DeviceManager();
    }
    return *instance;
}

void DeviceManager::addDevice(Device* device) {
    if (device != NULL) {
        devices[device->getId()] = device;
        std::cout << "[DeviceManager] Device added: " << device->getName()
                  << " (ID: " << device->getId() << ")" << std::endl;
    }
}

bool DeviceManager::removeDevice(int id) {
    std::map<int, Device*>::iterator it = devices.find(id);
    if (it != devices.end()) {
        delete it->second;
        devices.erase(it);
        std::cout << "[DeviceManager] Device removed: ID " << id << std::endl;
        return true;
    }
    return false;
}

Device* DeviceManager::getDevice(int id) {
    std::map<int, Device*>::iterator it = devices.find(id);
    if (it != devices.end()) {
        return it->second;
    }
    return NULL;
}
