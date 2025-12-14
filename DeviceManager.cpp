#include "DeviceManager.h"
#include <iostream>

int DeviceManager::add(Device* d) {
    devices.push_back(d);
    return d->getId();
}

Device* DeviceManager::get(int id) {
    for (size_t i = 0; i < devices.size(); i++) {
        if (devices[i]->getId() == id) return devices[i];
    }
    return 0;
}

void DeviceManager::list() const {
    std::cout << "\n--- Device List ---\n";
    for (size_t i = 0; i < devices.size(); i++) {
        std::cout << devices[i]->getId() << " | "
                  << devices[i]->getName() << " | "
                  << devices[i]->getType() << " | "
                  << (devices[i]->isPoweredOn() ? "ON" : "OFF") << "\n";
        devices[i]->printDetails();
    }
}
