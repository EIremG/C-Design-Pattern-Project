#pragma once
#include "Device.h"
#include <vector>
#include <algorithm>

// Singleton Device Manager (LLR16, LLR32)
// Single Responsibility: Device lifecycle management
class DeviceManager {
private:
    static DeviceManager* instance;
    std::vector<Device*> devices;
    
    // Private constructor (Singleton pattern)
    DeviceManager();
    
    // Delete copy constructor and assignment operator
    DeviceManager(const DeviceManager&) = delete;
    DeviceManager& operator=(const DeviceManager&) = delete;
    
public:
    // Singleton instance getter
    static DeviceManager* getInstance();
    
    // Device management methods (LLR16)
    bool addDevice(Device* device);
    bool removeDevice(int deviceId);
    Device* getDeviceById(int id);
    std::vector<Device*> getAllDevices() const { return devices; }
    int getDeviceCount() const { return devices.size(); }
    
    // Display methods (LLR32)
    void listAllDevices() const;
    void listDevicesByType(DeviceType type) const;
    
    // Cleanup
    ~DeviceManager();
};