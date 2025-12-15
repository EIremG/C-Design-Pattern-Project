#pragma once
#include "devices/LightDevice.h"
#include "devices/CameraDevice.h"
#include "devices/TVDevice.h"
#include "devices/MusicSystemDevice.h"
#include "devices/DetectorFactory.h"
#include "devices/AlarmDevice.h"

class DeviceFactory {
public:
    static LightDevice* createLight(const std::string& name, const std::string& color = "white", int illumination = 50);
    static CameraDevice* createCamera(const std::string& name, bool motionDetection = false, int fps = 30, bool nightVision = false);
    static TVDevice* createTV(const std::string& name, int brandCode);
    static MusicSystemDevice* createMusicSystem(const std::string& name);
    static DetectorDevice* createDetector(int typeCode, const std::string& name, float threshold, float range);
    static AlarmDevice* getAlarmInstance();
};