#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

// UML'de belirtilen Enum Yapıları
enum DeviceType {
    LIGHT,
    CAMERA,
    TV,
    SMOKE_DETECTOR,
    GAS_DETECTOR
};

enum DeviceStatus {
    ACTIVE,
    INACTIVE,
    FAILED
};

class Device {
protected:
    int id;
    std::string name;
    bool powerState;
    DeviceType deviceType;
    DeviceStatus status;
    bool isCritical; // UML'deki LLR17: Kritik cihazlar kapatılamaz kuralı için

public:
    Device(int id, const std::string& name, DeviceType type, bool critical = false)
        : id(id), name(name), deviceType(type), isCritical(critical) {
        powerState = true; // Varsayılan açık
        status = ACTIVE;
    }

    virtual ~Device() {}

    virtual void powerOn() {
        if (status == FAILED) {
            std::cout << "[ERROR] Device " << name << " is FAILED. Cannot power on.\n";
            return;
        }
        powerState = true;
        status = ACTIVE;
        std::cout << "[DEVICE] " << name << " is now ON.\n";
    }

    virtual void powerOff() {
        if (isCritical) {
            std::cout << "[WARNING] Critical Device " << name << " cannot be turned OFF! (LLR17)\n";
            return;
        }
        powerState = false;
        status = INACTIVE;
        std::cout << "[DEVICE] " << name << " is now OFF.\n";
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    DeviceStatus getStatus() const { return status; }
};

#endif