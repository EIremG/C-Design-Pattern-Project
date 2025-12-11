#pragma once
#include "Device.h"

// Singleton Alarm actuator (LLR13)
class Alarm : public Device {
private:
    static Alarm* instance;
    bool isAlarming;
    std::string alarmReason;
    
    // Private constructor (Singleton pattern)
    Alarm();
    
    // Delete copy constructor and assignment operator
    Alarm(const Alarm&) = delete;
    Alarm& operator=(const Alarm&) = delete;
    
public:
    // Singleton instance getter
    static Alarm* getInstance();
    
    // Override methods
    bool powerOn() override;
    bool powerOff() override; // LLR17 - Cannot power off
    std::string getStatus() const override;
    Device* clone() const override; // Cannot clone singleton
    
    // Specific methods
    void trigger(const std::string& reason);
    void silence();
    bool isActive() const { return isAlarming; }
};