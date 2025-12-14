#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <vector>
#include "Device.h"

class DeviceManager {
private:
    std::vector<Device*> devices;
    int nextId;

public:
    DeviceManager() : nextId(1) {}

    int add(Device* d);
    Device* get(int id);
    void list() const;
};

#endif
