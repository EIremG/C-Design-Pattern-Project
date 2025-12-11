#pragma once
#include "Device.h"

enum class TVModel {
    SAMSUNG,
    LG,
    SONY
};

// TV device (LLR33)
class TV : public Device {
private:
    TVModel model;
    int channel;
    int volume;
    
public:
    TV(const std::string& name, TVModel model = TVModel::SAMSUNG);
    
    // Override methods
    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override; // LLR15
    
    // Specific methods (LLR33)
    void changeChannel(int newChannel);
    void setVolume(int vol);
    TVModel getModel() const { return model; }
    int getChannel() const { return channel; }
    int getVolume() const { return volume; }
    
    static std::string modelToString(TVModel model);
};