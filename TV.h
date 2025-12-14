#ifndef TV_H
#define TV_H

#include "../core/Device.h"
#include <string>

class TV : public Device {
private:
    std::string model;

public:
    TV(int id, const std::string& name);

    void setModel(const std::string&);
    virtual void printDetails() const;

    virtual void powerOn();
    virtual void powerOff();
};

#endif
