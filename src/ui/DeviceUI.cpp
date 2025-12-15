#include "ui/DeviceUI.h"
#include "ui/Input.h"
#include <iostream>

void DeviceUI::printDeviceTypeMenu() {
    std::cout << "\n--- ADD DEVICE ---\n"
        << "1) Light\n"
        << "2) TV\n"
        << "3) Camera\n"
        << "4) Smoke Detector\n"
        << "5) Gas Detector\n";
}

DeviceAddRequest DeviceUI::promptAddRequest() {
    DeviceAddRequest req;

    printDeviceTypeMenu();
    int t = Input::readIntInRange("Device type (1-5): ", 1, 5);
    req.type = (UiDeviceType)t;

    Input::readLine("Name: ", req.name);

    // Clone sorusu (ileride Dev C/B ile uyumlu şekilde kullanılabilir)
    int c = Input::readIntInRange("Copy config from existing device? (0=no, 1=yes): ", 0, 1);
    req.cloneFromExisting = (c == 1);
    if (req.cloneFromExisting) {
        req.cloneSourceId = Input::readIntInRange("Source device id: ", 1, 1000000);
    }

    if (req.type == UI_LIGHT) {
        Input::readLine("Light color (e.g. white/red/blue): ", req.lightColor);
        req.lightIllumination = Input::readIntInRange("Illumination (0-100): ", 0, 100);
    }
    else if (req.type == UI_TV) {
        std::cout << "TV Model: 1) Samsung  2) LG\n";
        req.tvModel = Input::readIntInRange("Select (1-2): ", 1, 2);
    }
    // Camera/Detector config’leri Dev D/E modülünde olabilir; burada sadece temel isim aldık.

    return req;
}

int DeviceUI::promptRemoveId() {
    std::cout << "\n--- REMOVE DEVICE ---\n";
    return Input::readIntInRange("Device id: ", 1, 1000000);
}
