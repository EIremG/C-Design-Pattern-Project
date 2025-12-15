#ifndef DETECTOR_FACTORY_H
#define DETECTOR_FACTORY_H

#include "alarm/Detector.h"

class DetectorFactory {
public:
    // UML'deki yapıya uygun olarak DeviceType kullanıyoruz
    static Detector* createDetector(DeviceType type, int id) {
        switch (type) {
            case SMOKE_DETECTOR:
                return new SmokeDetector(id);
            case GAS_DETECTOR:
                return new GasDetector(id);
            default:
                return nullptr;
        }
    }
};

#endif