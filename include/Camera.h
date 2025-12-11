#pragma once
#include "Device.h"

// Camera device (LLR34)
class Camera : public Device {
private:
    bool motionDetection;
    int fps;
    bool nightVision;
    bool isRecording;
    
public:
    Camera(const std::string& name, bool motionDetection = true, int fps = 30, bool nightVision = false);
    
    // Override methods
    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override; // LLR15
    
    // Specific methods (LLR34)
    void startRecording();
    void stopRecording();
    void setMotionDetection(bool enabled);
    void setFPS(int newFps);
    void setNightVision(bool enabled);
    
    bool getMotionDetection() const { return motionDetection; }
    int getFPS() const { return fps; }
    bool getNightVision() const { return nightVision; }
    bool getIsRecording() const { return isRecording; }
};