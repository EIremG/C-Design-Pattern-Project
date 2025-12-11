#include "../include/Camera.h"

Camera::Camera(const std::string& name, bool motionDetection, int fps, bool nightVision)
    : Device(name, DeviceType::CAMERA, false), // Not critical
      motionDetection(motionDetection), fps(fps), nightVision(nightVision),
      isRecording(false) {
    
    // Validation
    if (this->fps < 1) this->fps = 1;
    if (this->fps > 120) this->fps = 120;
}

bool Camera::powerOn() {
    if (powerState) {
        std::cout << "[" << name << "] Already ON" << std::endl;
        return false;
    }
    
    powerState = true;
    std::cout << "📷 [CAMERA] " << name << " powered ON" << std::endl;
    std::cout << "   - FPS: " << fps << std::endl;
    std::cout << "   - Motion Detection: " << (motionDetection ? "ENABLED" : "DISABLED") << std::endl;
    std::cout << "   - Night Vision: " << (nightVision ? "ENABLED" : "DISABLED") << std::endl;
    return true;
}

bool Camera::powerOff() {
    if (!powerState) {
        std::cout << "[" << name << "] Already OFF" << std::endl;
        return false;
    }
    
    if (isRecording) {
        stopRecording();
    }
    
    powerState = false;
    std::cout << "📷 [CAMERA] " << name << " powered OFF" << std::endl;
    return true;
}

std::string Camera::getStatus() const {
    std::string status = "Camera [" + name + "] (ID: " + std::to_string(id) + ")";
    status += " - Status: " + std::string(powerState ? "ON" : "OFF");
    status += " | FPS: " + std::to_string(fps);
    status += " | Motion: " + std::string(motionDetection ? "ON" : "OFF");
    status += " | NightVision: " + std::string(nightVision ? "ON" : "OFF");
    status += " | Recording: " + std::string(isRecording ? "YES" : "NO");
    return status;
}

void Camera::startRecording() {
    if (!powerState) {
        std::cout << "[" << name << "] Cannot record - Camera is OFF" << std::endl;
        return;
    }
    
    if (isRecording) {
        std::cout << "[" << name << "] Already recording" << std::endl;
        return;
    }
    
    isRecording = true;
    std::cout << "🔴 [" << name << "] Recording started at " << fps << " FPS" << std::endl;
}

void Camera::stopRecording() {
    if (!isRecording) {
        std::cout << "[" << name << "] Not recording" << std::endl;
        return;
    }
    
    isRecording = false;
    std::cout << "⏹ [" << name << "] Recording stopped" << std::endl;
}

void Camera::setMotionDetection(bool enabled) {
    motionDetection = enabled;
    std::cout << "[" << name << "] Motion detection " 
              << (enabled ? "ENABLED" : "DISABLED") << std::endl;
}

void Camera::setFPS(int newFps) {
    if (newFps < 1 || newFps > 120) {
        std::cout << "[" << name << "] Invalid FPS! Must be 1-120" << std::endl;
        return;
    }
    
    fps = newFps;
    std::cout << "[" << name << "] FPS set to " << fps << std::endl;
}

void Camera::setNightVision(bool enabled) {
    nightVision = enabled;
    std::cout << "[" << name << "] Night vision " 
              << (enabled ? "ENABLED" : "DISABLED") << std::endl;
}

Device* Camera::clone() const {
    // LLR15 - Prototype pattern
    return new Camera(name + "_copy", motionDetection, fps, nightVision);
}