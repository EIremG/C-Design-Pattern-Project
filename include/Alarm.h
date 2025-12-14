#pragma once
#include "Device.h" 

class Alarm : public Device {
private:
    static Alarm* instance;
    std::string triggerMessage;
    bool isTriggered;
    bool isSilenced;

    // LLR13 - Private constructor for Singleton
    Alarm(const std::string& name) 
        : Device(name, DeviceType::ALARM), isTriggered(false), isSilenced(false) {
        // powerOn is virtual, so calling it here is safe but often logged in the constructor body.
        logger->log(LogLevel::INFO, "Alarm Singleton created and ready.");
    }
    
public:
    // Delete copy/move constructors/operators
    Alarm(const Alarm&) = delete;
    void operator=(const Alarm&) = delete;

    // LLR13 - Singleton Access
    static Alarm* getInstance() {
        if (instance == nullptr) {
            instance = new Alarm("System Alarm");
        }
        return instance;
    }

    // LLR17 - Alarm is critical and cannot be powered off manually
    bool powerOff() override {
        logger->log(LogLevel::CRITICAL, "SECURITY ALERT: Attempt to power off the Alarm was blocked.");
        return false;
    }

    // LLR15 - Prototype implementation for Singleton
    // It overrides the pure virtual clone() but returns the single instance instead of a new object.
    Device* clone() const override {
        logger->log(LogLevel::WARNING, "Attempted to clone Alarm Singleton. Returning existing instance.");
        return Alarm::getInstance(); 
    }

    // LLR17 - Critical device flag
    bool isCritical() const override { return true; } 

    // Operational methods (trigger, silence, reset...)
    void trigger(const std::string& message) {
        // ... (implementation same as before)
        if (!isTriggered) {
            isTriggered = true;
            isSilenced = false;
            triggerMessage = message;
            logger->log(LogLevel::CRITICAL, "ALARM TRIGGERED: " + message);
        }
    }
    
    void silence() { /* ... */ }
    void reset() { /* ... */ }

    std::string getStatus() const override {
        return Device::getStatus() + 
               " | Triggered: " + (isTriggered ? "YES" : "NO") + 
               " | Silenced: " + (isSilenced ? "YES" : "NO") +
               " | Message: " + (isTriggered ? triggerMessage : "None");
    }
};

// Initialization of static member (often done in Alarm.cpp)
Alarm* Alarm::instance = nullptr;