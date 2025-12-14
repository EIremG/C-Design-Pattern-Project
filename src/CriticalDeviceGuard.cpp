#include "CriticalDeviceGuard.h"
#include <ctime>

const std::string CriticalDeviceGuard::ADMIN_PASSWORD = "admin123";

bool CriticalDeviceGuard::canPowerOff(Device* device) {
    if (device == nullptr) {
        logSecurityEvent("ERROR: Null device pointer");
        return false;
    }
    
    if (device->isCriticalDevice()) {
        logSecurityEvent("BLOCKED: Attempted to power off critical device - " + 
                        device->getName() + " (ID: " + std::to_string(device->getId()) + ")");
        return false;
    }
    
    return true;
}

bool CriticalDeviceGuard::requestAdminOverride(Device* device, const std::string& password) {
    if (device == nullptr) {
        logSecurityEvent("ERROR: Null device in admin override request");
        return false;
    }
    
    logSecurityEvent("ADMIN OVERRIDE REQUESTED for device: " + device->getName());
    
    if (password == ADMIN_PASSWORD) {
        logSecurityEvent("ADMIN OVERRIDE GRANTED for device: " + device->getName());
        std::cout << "🔓 [SECURITY] Admin override granted for " << device->getName() << std::endl;
        return true;
    } else {
        logSecurityEvent("ADMIN OVERRIDE DENIED - Invalid password for device: " + 
                        device->getName());
        std::cout << "🔒 [SECURITY] Admin override DENIED - Invalid password!" << std::endl;
        return false;
    }
}

void CriticalDeviceGuard::logSecurityEvent(const std::string& event) {
    time_t now = time(0);
    char* dt = ctime(&now);
    
    std::string timestamp(dt);
    timestamp = timestamp.substr(0, timestamp.length() - 1);
    
    std::cout << "[SECURITY LOG] [" << timestamp << "] " << event << std::endl;
}