#pragma once
#include "Device.h"

enum class TVBrand {
    SAMSUNG = 0,
    LG = 1,
    SONY = 2
};

class TV : public Device {
private:
    TVBrand brand;
    int volume;
    int channel;

public:
    TV(const std::string& name, TVBrand brand);

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override;

    void changeChannel(int newChannel);
    void setVolume(int vol);
    std::string brandToString(TVBrand brand) const;
};