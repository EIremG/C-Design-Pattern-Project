#pragma once
#include "Device.h"

// Music System device (LLR10)
class MusicSystem : public Device {
private:
    int volume;
    std::string currentTrack;
    bool isPlaying;
    
public:
    MusicSystem(const std::string& name);
    
    // Override methods
    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override; // LLR15
    
    // Specific methods
    void play(const std::string& trackName);
    void pause();
    void stop();
    void setVolume(int vol);
    int getVolume() const { return volume; }
    std::string getCurrentTrack() const { return currentTrack; }
    bool getIsPlaying() const { return isPlaying; }
};