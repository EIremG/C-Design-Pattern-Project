#pragma once
#include "Device.h"
#include <string>

class CriticalDeviceGuard {
private:
    static const std::string ADMIN_PASSWORD;
    static void logSecurityEvent(const std::string& event);

public:
    static bool canPowerOff(Device* device);
    static bool requestAdminOverride(Device* device, const std::string& password);
};