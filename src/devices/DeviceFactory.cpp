#include "devices/DeviceFactory.h"
#include "devices/LightDevice.h"
#include "devices/CameraDevice.h"
#include "devices/TVDevice.h"
#include "devices/MusicSystemDevice.h"
#include "devices/AlarmDevice.h"
#include "devices/DetectorFactory.h"
#include <iostream>

LightDevice* DeviceFactory::createLight(const std::string& name,
    const std::string& color,
    int illumination)
{
    std::cout << "[FACTORY] Creating LightDevice: " << name << std::endl;
    return new LightDevice(name, color, illumination);
}

CameraDevice* DeviceFactory::createCamera(const std::string& name,
    bool motionDetection,
    int fps,
    bool nightVision)
{
    std::cout << "[FACTORY] Creating CameraDevice: " << name << std::endl;
    return new CameraDevice(name, motionDetection, fps, nightVision);
}

TVDevice* DeviceFactory::createTV(const std::string& name, int brandCode)
{
    std::cout << "[FACTORY] Creating TVDevice: " << name << std::endl;

    TVBrand brand =
        (brandCode == 0) ? TVBrand::SAMSUNG :
        (brandCode == 1) ? TVBrand::LG :
        TVBrand::SONY;

    return new TVDevice(name, brand);
}

MusicSystemDevice* DeviceFactory::createMusicSystem(const std::string& name)
{
    std::cout << "[FACTORY] Creating MusicSystemDevice: " << name << std::endl;
    return new MusicSystemDevice(name);
}

AlarmDevice* DeviceFactory::getAlarmInstance()
{
    std::cout << "[FACTORY] Getting AlarmDevice instance (Singleton)" << std::endl;
    return AlarmDevice::getInstance();
}

DetectorDevice* DeviceFactory::createDetector(int typeCode,
    const std::string& name,
    float threshold,
    float range)
{
    DetectorType type = (typeCode == 0) ? DetectorType::SMOKE : DetectorType::GAS;
    return DetectorFactory::createDetector(type, name, threshold, range);
}
