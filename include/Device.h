#pragma once
#include <iostream>
#include <string>
#include "Logger.h" 

enum class DeviceType {
    LIGHT = 0,
    CAMERA = 1,
    TV = 2,
    MUSIC_SYSTEM = 3,
    SMOKE_DETECTOR = 4,
    GAS_DETECTOR = 5,
    ALARM = 6
};

class Device {
private:
    static int nextID;
    int id;
    DeviceType deviceType;
    bool isCritical;

protected: 
    std::string name;
    bool powerState;
    Logger* logger;

    Device(const std::string& name, DeviceType type, bool critical = false);

public:
    virtual ~Device();

    static int getNextID() { return nextID; }

    // Pure virtual functions
    virtual bool powerOn() = 0;
    virtual bool powerOff() = 0;
    virtual Device* clone() const = 0;
    virtual std::string getStatus() const = 0;

    // Getter methods
    int getId() const { return id; }
    std::string getName() const { return name; }
    DeviceType getDeviceType() const { return deviceType; }
    bool getPowerState() const { return powerState; }
    bool isCriticalDevice() const { return isCritical; }

    // Helper
    static std::string deviceTypeToString(DeviceType type);
};