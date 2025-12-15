#include "devices/MusicSystemDevice.h"
#include <iostream>
#include <sstream>

static std::string toStrInt(int v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

MusicSystemDevice::MusicSystemDevice(const std::string& name)
    : HomeDevice(name, DeviceType::MUSIC_SYSTEM, false),
    volume(50), currentTrack("No track"), isPlaying(false)
{
}

bool MusicSystemDevice::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON\n";
        return false;
    }
    powerState = true;
    std::cout << "[MUSIC] " << name << " powered ON - Volume: " << volume << "%\n";
    return true;
}

bool MusicSystemDevice::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF\n";
        return false;
    }

    if (isPlaying) stop();

    powerState = false;
    std::cout << "[MUSIC] " << name << " powered OFF\n";
    return true;
}

std::string MusicSystemDevice::getStatus() const {
    std::string status = "MusicSystemDevice [" + name + "] (ID: " + toStrInt(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | Volume: " + toStrInt(volume) + "%";
    status += " | Current: " + currentTrack;
    status += " | Playing: " + std::string(isPlaying ? "YES" : "NO");
    return status;
}

void MusicSystemDevice::play(const std::string& trackName) {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot play - Device is OFF\n";
        return;
    }

    currentTrack = trackName;
    isPlaying = true;
    std::cout << "[" << name << "] Now playing: " << trackName
        << " at volume " << volume << "%\n";
}

void MusicSystemDevice::pause() {
    if (!isPlaying) {
        std::cout << "[" << name << "] Nothing is playing\n";
        return;
    }

    isPlaying = false;
    std::cout << "[" << name << "] Paused: " << currentTrack << "\n";
}

void MusicSystemDevice::stop() {
    if (!isPlaying && currentTrack == "No track") {
        std::cout << "[" << name << "] Already stopped\n";
        return;
    }

    isPlaying = false;
    std::cout << "[" << name << "] Stopped: " << currentTrack << "\n";
    currentTrack = "No track";
}

void MusicSystemDevice::setVolume(int vol) {
    if (vol < 0 || vol > 100) {
        std::cout << "[" << name << "] Invalid volume! Must be 0-100\n";
        return;
    }

    volume = vol;
    std::cout << "[" << name << "] Volume set to " << volume << "%\n";
}

HomeDevice* MusicSystemDevice::clone() const {
    MusicSystemDevice* copy = new MusicSystemDevice(name + "_copy");
    copy->volume = this->volume;
    copy->currentTrack = this->currentTrack;
    copy->isPlaying = this->isPlaying;
    return copy;
}
