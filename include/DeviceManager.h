#include "Device.h" // Also serves as DeviceManager.h
#include "CriticalDeviceGuard.h"
#include <vector>
#include <algorithm>
#include <memory>
#include <map>

class DeviceManager {
private:
    static DeviceManager* instance;
    std::map<int, std::unique_ptr<Device>> devices; // Use map for O(1) ID lookup

    DeviceManager() {
        Logger::getInstance()->log(LogLevel::INFO, "DeviceManager Singleton initialized.");
    }

public:
    // Delete copy/move constructors/operators
    DeviceManager(const DeviceManager&) = delete;
    void operator=(const DeviceManager&) = delete;

    // LLR10 - Singleton Access
    static DeviceManager* getInstance() {
        if (instance == nullptr) {
            instance = new DeviceManager();
        }
        return instance;
    }

    // LLR16 - Add device
    void addDevice(Device* device) {
        if (device) {
            devices[device->getID()] = std::unique_ptr<Device>(device);
            Logger::getInstance()->log(LogLevel::INFO, "Device added: " + device->getName() + " (ID: " + std::to_string(device->getID()) + ")");
        }
    }

    // LLR16 - Remove device
    bool removeDevice(int id) {
        auto it = devices.find(id);
        if (it != devices.end()) {
            if (it->second->isCritical()) {
                 Logger::getInstance()->log(LogLevel::WARNING, "Attempt to remove critical device (" + it->second->getName() + ") blocked.");
                 return false;
            }
            std::string name = it->second->getName();
            devices.erase(it);
            Logger::getInstance()->log(LogLevel::INFO, "Device removed: " + name + " (ID: " + std::to_string(id) + ")");
            return true;
        }
        Logger::getInstance()->log(LogLevel::WARNING, "Device with ID " + std::to_string(id) + " not found for removal.");
        return false;
    }

    // LLR11 - Get device
    Device* getDeviceById(int id) const {
        auto it = devices.find(id);
        if (it != devices.end()) {
            return it->second.get();
        }
        Logger::getInstance()->log(LogLevel::WARNING, "Device with ID " + std::to_string(id) + " not found.");
        return nullptr;
    }

    // LLR32 - List all devices
    void listAllDevices() const {
        std::cout << "\n*** Registered Devices (" << devices.size() << ") ***" << std::endl;
        for (const auto& pair : devices) {
            std::cout << "  - " << pair.second->getStatus() << std::endl;
        }
        std::cout << "***********************************" << std::endl;
    }

    // LLR32 - List devices by type
    void listDevicesByType(DeviceType type) const {
        std::string typeStr;
        if (type == DeviceType::LIGHT) typeStr = "LIGHT";
        else typeStr = "Device"; // Simplification

        std::cout << "\n*** Registered " << typeStr << " Devices ***" << std::endl;
        for (const auto& pair : devices) {
            if (pair.second->getType() == type) {
                std::cout << "  - " << pair.second->getStatus() << std::endl;
            }
        }
        std::cout << "***********************************" << std::endl;
    }
};

// Initialize static member
DeviceManager* DeviceManager::instance = nullptr;