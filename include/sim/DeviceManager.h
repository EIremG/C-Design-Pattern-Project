#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "Device.h"
#include <map>

// Singleton Pattern - Device yoneticisi
class DeviceManager {
private:
    static DeviceManager* instance;

    std::map<int, Device*> devices;

    DeviceManager();
    DeviceManager(const DeviceManager&);
    DeviceManager& operator=(const DeviceManager&);

public:
    ~DeviceManager();

    // Singleton Pattern
    static DeviceManager& getInstance();

    void addDevice(Device* device);
    bool removeDevice(int id);
    Device* getDevice(int id);
};

#endif
