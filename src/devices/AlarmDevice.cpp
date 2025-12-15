#include "devices/AlarmDevice.h"
#include <iostream>
#include <sstream>

// C++98 string convert helper
static std::string toStrInt(int v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

AlarmDevice* AlarmDevice::instance = NULL;

AlarmDevice::AlarmDevice()
    : HomeDevice("System Alarm", DeviceType::ALARM, true),
    isAlarming(false),
    alarmReason("")
{
    powerState = true; // critical cihaz always ON
}

AlarmDevice* AlarmDevice::getInstance() {
    if (instance == NULL) {
        instance = new AlarmDevice();
        std::cout << "[SINGLETON] AlarmDevice instance created" << std::endl;
    }
    return instance;
}

bool AlarmDevice::powerOn() {
    std::cout << "[ALARM] Alarm is always ON (cannot be powered on/off)" << std::endl;
    return true;
}

bool AlarmDevice::powerOff() {
    std::cout << "[ERROR] Cannot power off AlarmDevice - CRITICAL DEVICE!" << std::endl;
    return false;
}

std::string AlarmDevice::getStatus() const {
    std::string status = "AlarmDevice (ID: " + toStrInt(getId()) + ")";
    status += " - Status: " + std::string(isAlarming ? "ACTIVE" : "SILENT");
    if (isAlarming) {
        status += " | Reason: " + alarmReason;
    }
    return status;
}

void AlarmDevice::trigger(const std::string& reason) {
    isAlarming = true;
    alarmReason = reason;
    std::cout << "\n[ALARM] TRIGGERED! Reason: " << reason << std::endl;
}

void AlarmDevice::silence() {
    if (!isAlarming) {
        std::cout << "[ALARM] No active alarm to silence" << std::endl;
        return;
    }

    std::cout << "[ALARM] Alarm silenced. Previous reason: " << alarmReason << std::endl;
    isAlarming = false;
    alarmReason = "";
}

HomeDevice* AlarmDevice::clone() const {
    std::cout << "[ERROR] Cannot clone AlarmDevice - Singleton pattern!" << std::endl;
    return NULL;
}
