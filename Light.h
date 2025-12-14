#ifndef LIGHT_H
#define LIGHT_H

#include "../core/Device.h"

class Light : public Device {
private:
    std::string color;
    int illumination;

public:
    Light(int id, const std::string& name);

    void setColor(const std::string&);
    void setIllumination(int);

    virtual void powerOn();
    virtual void powerOff();
    virtual void printDetails() const;
};

#endif
