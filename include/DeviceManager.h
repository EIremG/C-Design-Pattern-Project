#pragma once
#include "Device.h"
#include "CriticalDeviceGuard.h"
#include <vector>
#include <algorithm>

class DeviceManager {
private:
    static DeviceManager* instance;
    std::vector<Device*> devices;

    DeviceManager();

public:
    DeviceManager(const DeviceManager&) = delete;
    void operator=(const DeviceManager&) = delete;

    static DeviceManager* getInstance();

    void addDevice(Device* device);
    bool removeDevice(int id);
    Device* getDeviceById(int id) const;
    
    void listAllDevices() const;
    void listDevicesByType(DeviceType type) const;

    ~DeviceManager();
};