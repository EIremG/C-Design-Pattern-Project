#pragma once
#include <string>
#include <iostream>

enum class DeviceType {
    LIGHT,
    CAMERA,
    TV,
    SMOKE_DETECTOR,
    GAS_DETECTOR,
    ALARM,
    MUSIC_SYSTEM,
    UNKNOWN
};

class Device {
protected:
    int id;
    std::string name;
    bool powerState;
    DeviceType deviceType;
    bool isCritical;
    static int nextID;
    
    // Protected constructor - Abstract class (LLR9)
    Device(const std::string& name, DeviceType type, bool critical);
    
public:
    virtual ~Device() = default;
    
    // Pure virtual methods (LLR11)
    virtual bool powerOn() = 0;
    virtual bool powerOff() = 0;
    virtual std::string getStatus() const = 0;
    virtual Device* clone() const = 0; // LLR15 - Prototype pattern
    
    // Getters (LLR9)
    int getId() const { return id; }
    std::string getName() const { return name; }
    bool getPowerState() const { return powerState; }
    DeviceType getDeviceType() const { return deviceType; }
    bool isCriticalDevice() const { return isCritical; }
    
    // Helper methods
    static std::string deviceTypeToString(DeviceType type);
    static int getNextID() { return nextID; } // For testing LLR37
};