#include "devices/HomeDeviceManager.h"
#include <iostream>

HomeDeviceManager* HomeDeviceManager::instance = NULL;

HomeDeviceManager::HomeDeviceManager() {
    std::cout << "[HOME DEVICE MANAGER] Initialized" << std::endl;
}

HomeDeviceManager* HomeDeviceManager::getInstance() {
    if (instance == NULL) {
        instance = new HomeDeviceManager();
    }
    return instance;
}

void HomeDeviceManager::addDevice(HomeDevice* device) {
    if (device == NULL) {
        std::cout << "[MANAGER ERROR] Cannot add null device!\n";
        return;
    }

    devices.push_back(device);
    std::cout << "[MANAGER] Device added: " << device->getName()
        << " (ID: " << device->getId() << ")\n";
}

bool HomeDeviceManager::removeDevice(int deviceId) {
    for (std::vector<HomeDevice*>::iterator it = devices.begin();
        it != devices.end(); ++it)
    {
        if ((*it)->getId() == deviceId) {
            if ((*it)->isCriticalDevice()) {
                std::cout << "[MANAGER ERROR] Cannot remove critical device: "
                    << (*it)->getName() << "\n";
                return false;
            }

            std::cout << "[MANAGER] Device removed: " << (*it)->getName()
                << " (ID: " << deviceId << ")\n";
            delete* it;
            devices.erase(it);
            return true;
        }
    }

    std::cout << "[MANAGER ERROR] Device with ID " << deviceId << " not found!\n";
    return false;
}

HomeDevice* HomeDeviceManager::getDeviceById(int id) const {
    for (std::vector<HomeDevice*>::const_iterator it = devices.begin();
        it != devices.end(); ++it)
    {
        if ((*it)->getId() == id) return *it;
    }
    return NULL;
}

void HomeDeviceManager::listAllDevices() const {
    if (devices.empty()) {
        std::cout << "\n[DEVICE LIST] No devices registered\n\n";
        return;
    }

    std::cout << "\n========================================\n";
    std::cout << "         DEVICE LIST (LLR32)\n";
    std::cout << "========================================\n";
    std::cout << "Total Devices: " << (int)devices.size() << "\n\n";

    for (std::vector<HomeDevice*>::const_iterator it = devices.begin();
        it != devices.end(); ++it)
    {
        const HomeDevice* device = *it;
        std::cout << "ID: " << device->getId()
            << " | Name: " << device->getName()
            << " | Status: " << (device->getPowerState() ? "ON " : "OFF")
            << " | Type: " << HomeDevice::deviceTypeToString(device->getDeviceType())
            << (device->isCriticalDevice() ? " [CRITICAL]" : "")
            << "\n";
    }

    std::cout << "========================================\n\n";
}

void HomeDeviceManager::listDevicesByType(DeviceType type) const {
    std::cout << "\n[DEVICES OF TYPE: " << HomeDevice::deviceTypeToString(type) << "]\n";

    bool found = false;
    for (std::vector<HomeDevice*>::const_iterator it = devices.begin();
        it != devices.end(); ++it)
    {
        const HomeDevice* device = *it;
        if (device->getDeviceType() == type) {
            std::cout << device->getStatus() << "\n";
            found = true;
        }
    }

    if (!found) std::cout << "No devices of this type found.\n";
    std::cout << "\n";
}

HomeDeviceManager::~HomeDeviceManager() {
    std::cout << "[HOME DEVICE MANAGER] Cleaning up...\n";
    for (std::vector<HomeDevice*>::iterator it = devices.begin();
        it != devices.end(); ++it)
    {
        delete* it;
    }
    devices.clear();
}
