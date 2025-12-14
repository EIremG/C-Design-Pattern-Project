#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "Camera.h"

// Builder Pattern - LLR34: Camera olusturucu
class CameraBuilder {
private:
    Camera* camera;

public:
    CameraBuilder(int id, const std::string& name);
    ~CameraBuilder();

    // Builder Pattern: Fluent interface
    CameraBuilder& setMotionDetection(bool enabled);
    CameraBuilder& setFPS(int f);
    CameraBuilder& setNightVision(bool enabled);

    Camera* build();
};

#endif
