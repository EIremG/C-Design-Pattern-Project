#include "DeviceFactory.h"

Light* DeviceFactory::createLight(const std::string& name, const std::string& color, int illumination) {
    std::cout << "[FACTORY] Creating Light: " << name << std::endl;
    return new Light(name, color, illumination);
}

Camera* DeviceFactory::createCamera(const std::string& name, bool motionDetection, int fps, bool nightVision) {
    std::cout << "[FACTORY] Creating Camera: " << name << std::endl;
    return new Camera(name, motionDetection, fps, nightVision);
}

TV* DeviceFactory::createTV(const std::string& name, int brandCode) {
    std::cout << "[FACTORY] Creating TV: " << name << std::endl;
    TVBrand brand = (brandCode == 0) ? TVBrand::SAMSUNG : (brandCode == 1) ? TVBrand::LG : TVBrand::SONY;
    return new TV(name, brand);
}

MusicSystem* DeviceFactory::createMusicSystem(const std::string& name) {
    std::cout << "[FACTORY] Creating Music System: " << name << std::endl;
    return new MusicSystem(name);
}

Alarm* DeviceFactory::getAlarmInstance() {
    std::cout << "[FACTORY] Getting Alarm instance (Singleton)" << std::endl;
    return Alarm::getInstance();
}

Detector* DeviceFactory::createDetector(int typeCode, const std::string& name, float threshold, float range) {
    DetectorType type = (typeCode == 0) ? DetectorType::SMOKE : DetectorType::GAS;
    return DetectorFactory::createDetector(type, name, threshold, range);
}