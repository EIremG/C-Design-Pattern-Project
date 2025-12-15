#pragma once
#include "devices/HomeDevice.h"

enum class TVBrand {
    SAMSUNG = 0,
    LG = 1,
    SONY = 2
};

class TVDevice : public HomeDevice {
private:
    TVBrand brand;
    int volume;
    int channel;

public:
    TVDevice(const std::string& name, TVBrand brand);

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    HomeDevice* clone() const override;

    void changeChannel(int newChannel);
    void setVolume(int vol);
    std::string brandToString(TVBrand brand) const;
};