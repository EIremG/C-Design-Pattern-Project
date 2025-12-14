#include "Device.h" // Also serves as MusicSystem.h

class MusicSystem : public Device {
private:
    int volume;
    std::string currentSong;

public:
    MusicSystem(const std::string& name)
        : Device(name, DeviceType::MUSIC_SYSTEM), volume(50), currentSong("None") {}

    Device* clone() const override {
        return new MusicSystem(name);
    }

    void setVolume(int vol) {
        if (vol >= 0 && vol <= 100) {
            volume = vol;
            logger->log(LogLevel::INFO, getName() + " volume set to " + std::to_string(volume) + ".");
        }
    }

    void play(const std::string& songName) {
        currentSong = songName;
        logger->log(LogLevel::INFO, getName() + " now playing: " + currentSong + ".");
    }

    std::string getStatus() const override {
        return Device::getStatus() + " | Volume: " + std::to_string(volume) + " | Song: " + currentSong;
    }

    bool isCritical() const override { return false; }
};