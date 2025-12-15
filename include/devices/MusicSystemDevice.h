#pragma once
#include "devices/HomeDevice.h"

class MusicSystemDevice : public HomeDevice {
private:
    int volume;
    std::string currentTrack;
    bool isPlaying;

public:
    MusicSystemDevice(const std::string& name);

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    HomeDevice* clone() const override;

    void play(const std::string& trackName);
    void pause();
    void stop();
    void setVolume(int vol);
};