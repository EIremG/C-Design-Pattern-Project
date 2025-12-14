#pragma once
#include "Device.h"

class MusicSystem : public Device {
private:
    int volume;
    std::string currentTrack;
    bool isPlaying;

public:
    MusicSystem(const std::string& name);

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override;

    void play(const std::string& trackName);
    void pause();
    void stop();
    void setVolume(int vol);
};