#include "Light.h" // Also serves as DeviceFactory.h
#include "Camera.h"
#include "TV.h"
#include "MusicSystem.h"
#include "SmokeDetector.h"
#include "GasDetector.h"
#include "Alarm.h"

class DeviceFactory {
public:
    // LLR9 - Factory Methods
    static Light* createLight(const std::string& name, const std::string& color = "white", int illumination = 50) {
        return new Light(name, color, illumination);
    }

    static Camera* createCamera(const std::string& name, bool isRecording = false, int fps = 30, bool nightVision = false) {
        return new Camera(name, isRecording, fps, nightVision);
    }

    // Note: Parameter is an int in the test, mapping to TVBrand enum here
    static TV* createTV(const std::string& name, int brandCode) {
        TVBrand brand = (brandCode == 0) ? TVBrand::SAMSUNG : (brandCode == 1) ? TVBrand::LG : TVBrand::SONY;
        return new TV(name, brand);
    }

    static MusicSystem* createMusicSystem(const std::string& name) {
        return new MusicSystem(name);
    }

    // Note: First parameter is an int in the test, mapping to Detector type here
    static Detector* createDetector(int typeCode, const std::string& name, float threshold, float range) {
        if (typeCode == 0) {
            return new SmokeDetector(name, threshold, range);
        } else if (typeCode == 1) {
            return new GasDetector(name, threshold, range);
        }
        return nullptr;
    }
    
    // LLR13 - Get Alarm Singleton
    static Alarm* getAlarmInstance() {
        return Alarm::getInstance();
    }
};
