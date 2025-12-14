#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"

// LLR10: Camera sinifi
class Camera : public Device {
private:
    bool motionDetection;
    int fps;
    bool nightVision;

public:
    Camera(int id, const std::string& name);
    virtual ~Camera();

    // Device'dan override edilen fonksiyonlar
    void powerOn();
    void powerOff();

    // LLR10: Camera ozellikleri
    void enableMotionDetection();
    void disableMotionDetection();
    void setFPS(int f);
    void setNightVision(bool enabled);

    // LLR25: Motion detection
    void detectMotion();
    void startRecording();
    void stopRecording();

    // CameraBuilder icin gerekli
    friend class CameraBuilder;
};

#endif
