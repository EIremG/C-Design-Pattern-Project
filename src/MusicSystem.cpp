#include "../include/MusicSystem.h"

MusicSystem::MusicSystem(const std::string& name)
    : Device(name, DeviceType::MUSIC_SYSTEM, false), // Not critical
      volume(50), currentTrack("No track"), isPlaying(false) {
}

bool MusicSystem::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }
    powerState = true;
    std::cout << "[MUSIC SYSTEM] " << name << " powered ON - Volume: " << volume << "%" << std::endl;
    return true;
}

bool MusicSystem::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF" << std::endl;
        return false;
    }
    
    if (isPlaying) {
        stop();
    }
    
    powerState = false;
    std::cout << "[MUSIC SYSTEM] " << name << " powered OFF" << std::endl;
    return true;
}

std::string MusicSystem::getStatus() const {
    std::string status = "MusicSystem [" + name + "] (ID: " + std::to_string(id) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Volume: " + std::to_string(volume) + "%";
    status += " | Current: " + currentTrack;
    status += " | Playing: " + std::string(isPlaying ? "YES" : "NO");
    return status;
}

void MusicSystem::play(const std::string& trackName) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot play - Device is OFF" << std::endl;
        return;
    }
    
    currentTrack = trackName;
    isPlaying = true;
    std::cout << "♪ [" << name << "] Now playing: " << trackName 
              << " at volume " << volume << "%" << std::endl;
}

void MusicSystem::pause() {
    if (!isPlaying) {
        std::cout << "[" << name << "] Nothing is playing" << std::endl;
        return;
    }
    
    isPlaying = false;
    std::cout << "⏸ [" << name << "] Paused: " << currentTrack << std::endl;
}

void MusicSystem::stop() {
    if (!isPlaying && currentTrack == "No track") {
        std::cout << "[" << name << "] Already stopped" << std::endl;
        return;
    }
    
    isPlaying = false;
    std::cout << "⏹ [" << name << "] Stopped: " << currentTrack << std::endl;
    currentTrack = "No track";
}

void MusicSystem::setVolume(int vol) {
    if (vol < 0 || vol > 100) {
        std::cout << "[" << name << "] Invalid volume! Must be 0-100" << std::endl;
        return;
    }
    
    volume = vol;
    std::cout << "🔊 [" << name << "] Volume set to " << volume << "%" << std::endl;
}

Device* MusicSystem::clone() const {
    // LLR15 - Prototype pattern
    MusicSystem* copy = new MusicSystem(name + "_copy");
    copy->volume = this->volume;
    return copy;
}