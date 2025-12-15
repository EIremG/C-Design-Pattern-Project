#include "devices/CameraDevice.h"
#include <iostream>
#include <sstream>

static std::string toStrInt(int v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

CameraDevice::CameraDevice(const std::string& name, bool motionDetection, int fps, bool nightVision)
    : HomeDevice(name, DeviceType::CAMERA, false),
    motionDetection(motionDetection),
    fps(fps),
    nightVision(nightVision),
    isRecording(false)
{
    if (this->fps < 1) this->fps = 1;
    if (this->fps > 120) this->fps = 120;
}

bool CameraDevice::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }

    powerState = true;
    std::cout << "[CAMERA] " << name << " powered ON" << std::endl;
    std::cout << "   - FPS: " << fps << std::endl;
    std::cout << "   - Motion Detection: " << (motionDetection ? "ENABLED" : "DISABLED") << std::endl;
    std::cout << "   - Night Vision: " << (nightVision ? "ENABLED" : "DISABLED") << std::endl;
    return true;
}

bool CameraDevice::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF" << std::endl;
        return false;
    }

    if (isRecording) {
        stopRecording();
    }

    powerState = false;
    std::cout << "[CAMERA] " << name << " powered OFF" << std::endl;
    return true;
}

std::string CameraDevice::getStatus() const {
    std::string status = "CameraDevice [" + name + "] (ID: " + toStrInt(getId()) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | FPS: " + toStrInt(fps);
    status += " | Motion: " + std::string(motionDetection ? "ON" : "OFF");
    status += " | NightVision: " + std::string(nightVision ? "ON" : "OFF");
    status += " | Recording: " + std::string(isRecording ? "YES" : "NO");
    return status;
}

void CameraDevice::startRecording() {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot record - Camera is OFF" << std::endl;
        return;
    }

    if (isRecording) {
        std::cout << "[" << name << "] Already recording" << std::endl;
        return;
    }

    isRecording = true;
    std::cout << "[" << name << "] Recording started at " << fps << " FPS" << std::endl;
}

void CameraDevice::stopRecording() {
    if (!isRecording) {
        std::cout << "[" << name << "] Not recording" << std::endl;
        return;
    }

    isRecording = false;
    std::cout << "[" << name << "] Recording stopped" << std::endl;
}

void CameraDevice::setMotionDetection(bool enabled) {
    motionDetection = enabled;
    std::cout << "[" << name << "] Motion detection " << (enabled ? "ENABLED" : "DISABLED") << std::endl;
}

void CameraDevice::setFPS(int newFps) {
    if (newFps < 1 || newFps > 120) {
        std::cout << "[" << name << "] Invalid FPS! Must be 1-120" << std::endl;
        return;
    }

    fps = newFps;
    std::cout << "[" << name << "] FPS set to " << fps << std::endl;
}

void CameraDevice::setNightVision(bool enabled) {
    nightVision = enabled;
    std::cout << "[" << name << "] Night vision " << (enabled ? "ENABLED" : "DISABLED") << std::endl;
}

HomeDevice* CameraDevice::clone() const {
    return new CameraDevice(name + "_copy", motionDetection, fps, nightVision);
}
