#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include "DeviceTypes.h"

using std::string;

class Device {
private:
    int id;
    string name;
    bool powerState;
    bool isCriticalDeviceFlag;
    DeviceType deviceType;

    static int nextID; // ID generator

protected:
    // Protected constructor: sadece türev sınıflar çağırabilir
    Device(const string& name, DeviceType type, bool isCritical);

public:
    virtual ~Device() {}

    // Pure virtual methods
    virtual void powerOn() = 0;
    virtual bool powerOff() = 0; // true: success, false: failed (critical)
    virtual string getStatus() const = 0;

    // Clone method for Prototype Pattern
    virtual Device* clone() const = 0;

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    bool getPowerState() const { return powerState; }
    bool isCriticalDevice() const { return isCriticalDeviceFlag; }
    DeviceType getDeviceType() const { return deviceType; }

protected:
    // Protected setters for derived classes
    void setPowerState(bool state) { powerState = state; }
};

#endif // DEVICE_H
