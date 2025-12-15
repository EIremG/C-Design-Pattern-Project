#pragma once

#include "devices/HomeDevice.h"
#include "devices/CriticalDeviceGuard.h"
#include <vector>

class HomeDeviceManager {
private:
    static HomeDeviceManager* instance;
    std::vector<HomeDevice*> devices;

    HomeDeviceManager();

    // kopyalamayı kapat
    HomeDeviceManager(const HomeDeviceManager&);
    HomeDeviceManager& operator=(const HomeDeviceManager&);

public:
    static HomeDeviceManager* getInstance();

    void addDevice(HomeDevice* device);
    bool removeDevice(int id);
    HomeDevice* getDeviceById(int id) const;

    void listAllDevices() const;
    void listDevicesByType(DeviceType type) const;

    ~HomeDeviceManager();
};
