
#pragma once
#include <string>
#include <iostream>

enum class DeviceType {
    LIGHT,
    CAMERA,
    TV,
    SMOKE_DETECTOR,
    GAS_DETECTOR,
    MUSIC_SYSTEM
};

enum class DeviceStatus {
    ACTIVE,
    INACTIVE,
    FAILED
};

class Device {
protected:
    int id;
    std::string name;
    DeviceType deviceType;
    DeviceStatus status;
    bool isCritical;  // LLR17 - Critical devices cannot be powered off

public:
    Device(const std::string& name, DeviceType type, bool critical = false);
    virtual ~Device() = default;

    // LLR11 - Pure virtual methods
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual std::string getStatus() const;

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    DeviceType getDeviceType() const { return deviceType; }
    bool getIsCritical() const { return isCritical; }
    DeviceStatus getPowerState() const { return status; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
};