#include "../include/DeviceFactory.h"

Light* DeviceFactory::createLight(const std::string& name, 
                                  const std::string& color, 
                                  int illumination) {
    std::cout << "[FACTORY] Creating Light: " << name << std::endl;
    return new Light(name, color, illumination);
}

Camera* DeviceFactory::createCamera(const std::string& name, 
                                   bool motionDetection, 
                                   int fps, 
                                   bool nightVision) {
    std::cout << "[FACTORY] Creating Camera: " << name << std::endl;
    return new Camera(name, motionDetection, fps, nightVision);
}

TV* DeviceFactory::createTV(const std::string& name, TVModel model) {
    std::cout << "[FACTORY] Creating TV: " << name << std::endl;
    return new TV(name, model);
}

MusicSystem* DeviceFactory::createMusicSystem(const std::string& name) {
    std::cout << "[FACTORY] Creating Music System: " << name << std::endl;
    return new MusicSystem(name);
}

Alarm* DeviceFactory::getAlarmInstance() {
    std::cout << "[FACTORY] Getting Alarm instance (Singleton)" << std::endl;
    return Alarm::getInstance();
}

Detector* DeviceFactory::createDetector(DetectorType type, 
                                       const std::string& name,
                                       float sensitivity, 
                                       float threshold) {
    return DetectorFactory::createDetector(type, name, sensitivity, threshold);
}