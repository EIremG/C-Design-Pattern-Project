#ifndef DEVICE_UI_H
#define DEVICE_UI_H

#include "ui/DeviceRequests.h"

// Bu sınıf sadece kullanıcıdan input toplar.
// Gerçek add/remove/show işlemini AppServices -> DeviceManager (Dev B) yapacak.
class DeviceUI {
public:
    static void printDeviceTypeMenu();
    static DeviceAddRequest promptAddRequest();
    static int promptRemoveId();
};

#endif
