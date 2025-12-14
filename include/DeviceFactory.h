#pragma once
#include "Light.h"
#include "Camera.h"
#include "TV.h"
#include "MusicSystem.h"
#include "DetectorFactory.h"
#include "Alarm.h"

class DeviceFactory {
public:
    static Light* createLight(const std::string& name, const std::string& color = "white", int illumination = 50);
    static Camera* createCamera(const std::string& name, bool motionDetection = false, int fps = 30, bool nightVision = false);
    static TV* createTV(const std::string& name, int brandCode);
    static MusicSystem* createMusicSystem(const std::string& name);
    static Detector* createDetector(int typeCode, const std::string& name, float threshold, float range);
    static Alarm* getAlarmInstance();
};