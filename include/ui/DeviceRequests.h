#ifndef DEVICE_REQUESTS_H
#define DEVICE_REQUESTS_H

#include <string>

enum UiDeviceType {
    UI_LIGHT = 1,
    UI_TV = 2,
    UI_CAMERA = 3,
    UI_SMOKE_DETECTOR = 4,
    UI_GAS_DETECTOR = 5
};

struct DeviceAddRequest {
    UiDeviceType type;

    // ortak alanlar
    std::string name;

    // Light
    std::string lightColor;
    int lightIllumination;

    // TV
    int tvModel; // 1=Samsung, 2=LG

    // Clone config (LLR15 başka modülde ama UI checkbox’ı burada sorulabilir)
    bool cloneFromExisting;
    int  cloneSourceId;

    DeviceAddRequest()
        : type(UI_LIGHT),
        lightIllumination(50),
        tvModel(1),
        cloneFromExisting(false),
        cloneSourceId(-1) {
    }
};

#endif
