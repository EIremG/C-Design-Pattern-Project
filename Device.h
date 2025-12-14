#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    int id;
    std::string name;
    std::string type;
    bool powerState;

public:
    Device(int id, const std::string& name, const std::string& type)
        : id(id), name(name), type(type), powerState(false) {}

    virtual ~Device() {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }

    bool isPoweredOn() const { return powerState; }

    virtual void powerOn() = 0;
    virtual void powerOff() = 0;

    virtual void printDetails() const {}
};

#endif
