#include "../include/Alarm.h"

// Static member initialization
Alarm* Alarm::instance = nullptr;

Alarm::Alarm()
    : Device("System Alarm", DeviceType::ALARM, true), // Critical device
      isAlarming(false), alarmReason("") {
    powerState = true; // Alarm is always ON
}

Alarm* Alarm::getInstance() {
    if (instance == nullptr) {
        instance = new Alarm();
        std::cout << "[SINGLETON] Alarm instance created" << std::endl;
    }
    return instance;
}

bool Alarm::powerOn() {
    std::cout << "[ALARM] Alarm is always ON (cannot be powered on/off)" << std::endl;
    return true;
}

bool Alarm::powerOff() {
    // LLR17 - Critical device cannot be powered off
    std::cout << "[ERROR] Cannot power off Alarm - CRITICAL DEVICE!" << std::endl;
    return false;
}

std::string Alarm::getStatus() const {
    std::string status = "Alarm (ID: " + std::to_string(id) + ")";
    status += " - Status: " + std::string(isAlarming ? "🚨 ACTIVE" : "✅ SILENT");
    if (isAlarming) {
        status += " | Reason: " + alarmReason;
    }
    return status;
}

void Alarm::trigger(const std::string& reason) {
    isAlarming = true;
    alarmReason = reason;
    std::cout << "\n🚨🚨🚨 ALARM TRIGGERED! 🚨🚨🚨" << std::endl;
    std::cout << "Reason: " << reason << std::endl;
    std::cout << "🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨\n" << std::endl;
}

void Alarm::silence() {
    if (!isAlarming) {
        std::cout << "[ALARM] No active alarm to silence" << std::endl;
        return;
    }
    
    std::cout << "[ALARM] Alarm silenced. Previous reason: " << alarmReason << std::endl;
    isAlarming = false;
    alarmReason = "";
}

Device* Alarm::clone() const {
    // Cannot clone a singleton
    std::cout << "[ERROR] Cannot clone Alarm - Singleton pattern!" << std::endl;
    return nullptr;
}