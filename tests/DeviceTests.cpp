#include "DeviceTests.h"
#include "TinyTest.h"

#include "devices/HomeDeviceManager.h"
#include "devices/DeviceFactory.h"
#include "devices/HomeDevice.h"

void runDeviceTests(TinyTest& t)
{
    HomeDeviceManager* mgr = HomeDeviceManager::getInstance();

    // 1) Factory createLight null dönmemeli
    HomeDevice* light = DeviceFactory::createLight("T_Light", "white", 70);
    t.expectTrue(light != 0, "DeviceFactory::createLight returns non-null");

    if (light) {
        int id = light->getId();
        t.expectTrue(id > 0, "Light id is positive");

        // 2) Manager add + getById çalışmalı
        mgr->addDevice(light);
        t.expectTrue(mgr->getDeviceById(id) != 0, "HomeDeviceManager::getDeviceById finds added device");

        // 3) remove yanlış id -> false olmalı
        t.expectTrue(!mgr->removeDevice(99999999), "removeDevice invalid id returns false");

        // 4) remove doğru id -> true olmalı
        t.expectTrue(mgr->removeDevice(id), "removeDevice existing id returns true");
        t.expectTrue(mgr->getDeviceById(id) == 0, "getDeviceById returns null after remove");
    }

    // 5) clone: en garanti kontrol (id farklı varsaymayalım)
    HomeDevice* tv = DeviceFactory::createTV("T_TV", 1);
    t.expectTrue(tv != 0, "DeviceFactory::createTV returns non-null");

    if (tv) {
        HomeDevice* tv2 = tv->clone();
        t.expectTrue(tv2 != 0, "clone returns non-null");
        if (tv2) {
            t.expectTrue(tv2->getDeviceType() == tv->getDeviceType(), "clone keeps device type");
            // cleanup: manager’a eklemedik, direkt sil
            delete tv2;
        }
        delete tv;
    }
}
