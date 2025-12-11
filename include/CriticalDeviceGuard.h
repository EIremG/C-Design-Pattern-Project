#pragma once
#include "Device.h"

// Security guard for critical devices (LLR17)
// Single Responsibility: Security validation
class CriticalDeviceGuard {
private:
    static const std::string ADMIN_PASSWORD;
    
public:
    // Check if device can be powered off
    static bool canPowerOff(Device* device);
    
    // Request admin override with password
    static bool requestAdminOverride(Device* device, const std::string& password);
    
    // Log security events
    static void logSecurityEvent(const std::string& event);
    
private:
    CriticalDeviceGuard() = delete; // Prevent instantiation
};