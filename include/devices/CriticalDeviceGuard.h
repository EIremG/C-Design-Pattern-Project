#pragma once
#include "devices/HomeDevice.h"
#include <string>

class CriticalDeviceGuard {
private:
    static const std::string ADMIN_PASSWORD;
    static void logSecurityEvent(const std::string& event);

public:
    static bool canPowerOff(HomeDevice* device);
    static bool requestAdminOverride(HomeDevice* device, const std::string& password);
};