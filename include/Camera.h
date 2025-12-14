#pragma once
#include "Device.h" 

class Camera : public Device {
private:
    bool isRecording;
    int framesPerSecond;
    bool nightVisionEnabled;

public:
    Camera(const std::string& name, bool isRecording, int fps, bool nightVision)
        // Device kurucusu (protected) çağrılıyor. name artık protected olduğu için sorun yok.
        : Device(name, DeviceType::CAMERA), isRecording(isRecording), framesPerSecond(fps), nightVisionEnabled(nightVision) {}

    // LLR15 - Prototype implementation
    Device* clone() const override {
        return new Camera(name, isRecording, framesPerSecond, nightVisionEnabled);
    }

    // LLR17 - Criticality check
    bool isCritical() const override { return false; }

    // LLR34 - Specific operations
    void startRecording() {
        // Hata çözüldü: isPoweredOn değişkenine doğrudan erişim yerine public metot kullanıldı.
        if (isPoweredOn()) { 
            isRecording = true;
            logger->log(LogLevel::INFO, getName() + " started recording.");
        } else {
             logger->log(LogLevel::WARNING, getName() + " is OFF and cannot start recording.");
        }
    }

    void stopRecording() {
        isRecording = false;
        logger->log(LogLevel::INFO, getName() + " stopped recording.");
    }

    void setFPS(int fps) { /* ... */ }
    void setNightVision(bool enable) { /* ... */ }

    std::string getStatus() const override {
        return Device::getStatus() + " | Recording: " + (isRecording ? "YES" : "NO") + 
               " | FPS: " + std::to_string(framesPerSecond) + 
               " | NightVision: " + (nightVisionEnabled ? "ON" : "OFF");
    }
};