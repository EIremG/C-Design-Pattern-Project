#pragma once
#include "Device.h"

class Camera : public Device {
private:
    bool motionDetection;
    int fps;
    bool nightVision;
    bool isRecording;

public:
    Camera(const std::string& name, bool motionDetection = false, int fps = 30, bool nightVision = false);

    bool powerOn() override;
    bool powerOff() override;
    std::string getStatus() const override;
    Device* clone() const override;

    void startRecording();
    void stopRecording();
    void setMotionDetection(bool enabled);
    void setFPS(int newFps);
    void setNightVision(bool enabled);
};