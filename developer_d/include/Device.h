#ifndef DEVICE_H
#define DEVICE_H

#include <string>

// LLR10: Abstract Device sinifi
class Device {
protected:
    int deviceId;
    std::string name;
    std::string status;

public:
    Device(int id, const std::string& deviceName);
    virtual ~Device();

    // Saf sanal fonksiyonlar
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;

    std::string getStatus() const;
    int getId() const;
    std::string getName() const;
    void setFailed();
};

#endif
