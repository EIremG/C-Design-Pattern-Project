#include "Device.h" // Also serves as CriticalDeviceGuard.h

class CriticalDeviceGuard {
public:
    // LLR17 - Main Check
    static bool canPowerOff(Device* device) {
        if (device->isCritical()) {
            Logger::getInstance()->log(LogLevel::CRITICAL, "CRITICAL GUARD: Power-off blocked for " + device->getName() + ".");
            return false;
        }
        return true;
    }

    // LLR17 - Admin Override (Example of a secure bypass)
    static bool requestAdminOverride(Device* device, const std::string& password) {
        if (device->isCritical()) {
            if (password == "admin123") {
                Logger::getInstance()->log(LogLevel::CRITICAL, "ADMIN OVERRIDE GRANTED: Temporary bypass for " + device->getName() + ".");
                // In a real system, this would set a temporary flag on the device
                return true;
            } else {
                Logger::getInstance()->log(LogLevel::CRITICAL, "ADMIN OVERRIDE FAILED: Invalid password attempt on " + device->getName() + ".");
                return false;
            }
        }
        return true;
    }
};