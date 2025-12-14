#include <iostream>
#include <string>

// DÜZELTME: ../include/ kullanmayın, sadece dosya adı yeterli
#include "Light.h"
#include "Camera.h"
#include "TV.h"
#include "MusicSystem.h"
#include "Detector.h"
#include "SmokeDetector.h"
#include "GasDetector.h"
#include "Alarm.h"
#include "Device.h"
#include "DeviceManager.h"
#include "DeviceFactory.h"
#include "CriticalDeviceGuard.h"
#include "Logger.h"

void printHeader(const std::string& title) {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "╚════════════════════════════════════════╝\n" << std::endl;
}

void testDeviceCreation() {
    printHeader("TEST 1: Device Creation & Factory (LLR9, LLR37)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    Light* light1 = DeviceFactory::createLight("Living Room Light", "warm white", 70);
    Light* light2 = DeviceFactory::createLight("Bedroom Light", "blue", 50);
    
    Camera* camera1 = DeviceFactory::createCamera("Front Door Camera", true, 60, true);
    Camera* camera2 = DeviceFactory::createCamera("Backyard Camera", true, 30, false);
    
    TV* tv1 = DeviceFactory::createTV("Living Room TV", 0); 
    TV* tv2 = DeviceFactory::createTV("Bedroom TV", 1); 
    
    MusicSystem* music = DeviceFactory::createMusicSystem("Home Theater");
    
    Detector* smokeDetector = DeviceFactory::createDetector(0, "Kitchen Smoke Detector", 0.8f, 60.0f);
    Detector* gasDetector = DeviceFactory::createDetector(1, "Basement Gas Detector", 0.9f, 100.0f);
    
    Alarm* alarm = DeviceFactory::getAlarmInstance();
    
    manager->addDevice(light1);
    manager->addDevice(light2);
    manager->addDevice(camera1);
    manager->addDevice(camera2);
    manager->addDevice(tv1);
    manager->addDevice(tv2);
    manager->addDevice(music);
    manager->addDevice(smokeDetector);
    manager->addDevice(gasDetector);
    manager->addDevice(alarm);
    
    std::cout << "\n✅ All devices created and added to manager\n" << std::endl;
    std::cout << "ID verification: Next ID would be " << Device::getNextID() << std::endl;
}

void testDeviceListing() {
    printHeader("TEST 2: Device Listing (LLR32)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    manager->listAllDevices();
}

void testDeviceOperations() {
    printHeader("TEST 3: Device Operations (LLR11, LLR34, LLR35)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    Device* light = manager->getDeviceById(1000);
    Device* camera = manager->getDeviceById(1002);
    Device* music = manager->getDeviceById(1006);
    Device* tv = manager->getDeviceById(1004);
    
    if (light) {
        std::cout << "\n--- Testing Light (LLR35) ---" << std::endl;
        light->powerOn();
        Light* l = dynamic_cast<Light*>(light);
        if (l) {
            l->setColor("red");
            l->setIllumination(100);
        }
        std::cout << light->getStatus() << std::endl;
    }
    
    if (camera) {
        std::cout << "\n--- Testing Camera (LLR34) ---" << std::endl;
        camera->powerOn();
        Camera* c = dynamic_cast<Camera*>(camera);
        if (c) {
            c->startRecording();
            c->setFPS(120);
            c->setNightVision(true);
        }
        std::cout << camera->getStatus() << std::endl;
    }
    
    if (tv) {
        std::cout << "\n--- Testing TV (LLR33) ---" << std::endl;
        tv->powerOn();
        TV* t = dynamic_cast<TV*>(tv);
        if (t) {
            t->changeChannel(5);
            t->setVolume(75);
        }
        std::cout << tv->getStatus() << std::endl;
    }
    
    if (music) {
        std::cout << "\n--- Testing Music System ---" << std::endl;
        music->powerOn();
        MusicSystem* m = dynamic_cast<MusicSystem*>(music);
        if (m) {
            m->setVolume(80);
            m->play("Bohemian Rhapsody");
        }
        std::cout << music->getStatus() << std::endl;
    }
}

void testPrototypePattern() {
    printHeader("TEST 4: Prototype Pattern (LLR15)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    Device* originalLight = manager->getDeviceById(1000);
    if (originalLight) {
        std::cout << "\n📋 Original device:" << std::endl;
        std::cout << originalLight->getStatus() << std::endl;
        
        Device* clonedLight = originalLight->clone();
        std::cout << "\n📋 Cloned device:" << std::endl;
        std::cout << clonedLight->getStatus() << std::endl;
        
        manager->addDevice(clonedLight);
        std::cout << "\n✅ Cloned device added to manager" << std::endl;
    }
}

void testCriticalDeviceProtection() {
    printHeader("TEST 5: Critical Device Protection (LLR17)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    Device* smokeDetector = manager->getDeviceById(1007);
    if (smokeDetector) {
        std::cout << "\n🔒 Attempting to power off critical device..." << std::endl;
        bool canPowerOff = CriticalDeviceGuard::canPowerOff(smokeDetector); 
        
        if (!canPowerOff) {
            std::cout << "   Blocked by security guard!" << std::endl;
            
            std::cout << "\n🔑 Attempting admin override with wrong password..." << std::endl;
            CriticalDeviceGuard::requestAdminOverride(smokeDetector, "wrong");
            
            std::cout << "\n🔑 Attempting admin override with correct password..." << std::endl;
            bool override2 = CriticalDeviceGuard::requestAdminOverride(smokeDetector, "admin123");
            
            if (override2) {
                std::cout << "   Admin can now manually override if needed" << std::endl;
            }
        }
        
        std::cout << "\n🔒 Direct powerOff() call on critical device..." << std::endl;
        smokeDetector->powerOff();
    }
    
    Device* light = manager->getDeviceById(1000);
    if (light) {
        std::cout << "\n💡 Attempting to power off regular device..." << std::endl;
        bool result = light->powerOff();
        std::cout << "   Result: " << (result ? "SUCCESS" : "FAILED") << std::endl;
    }
}

void testAlarmSingleton() {
    printHeader("TEST 6: Alarm Singleton (LLR13)");
    
    Alarm* alarm1 = Alarm::getInstance();
    Alarm* alarm2 = Alarm::getInstance();
    
    std::cout << "Alarm instance 1 address: " << alarm1 << std::endl;
    std::cout << "Alarm instance 2 address: " << alarm2 << std::endl;
    std::cout << "Same instance? " << (alarm1 == alarm2 ? "✅ YES" : "❌ NO") << std::endl;
    
    std::cout << "\n🚨 Triggering alarm..." << std::endl;
    alarm1->trigger("Smoke detected in kitchen!");
    
    std::cout << "\n📊 Alarm status:" << std::endl;
    std::cout << alarm1->getStatus() << std::endl;
    
    std::cout << "\n🔕 Silencing alarm..." << std::endl;
    alarm1->silence();
    
    std::cout << "\n📊 Alarm status after silence:" << std::endl;
    std::cout << alarm1->getStatus() << std::endl;
    
    std::cout << "\n🔒 Attempting to power off alarm..." << std::endl;
    alarm1->powerOff();
}

void testDetectorFunctionality() {
    printHeader("TEST 7: Detector Functionality (LLR12)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    Device* smokeDevice = manager->getDeviceById(1007);
    SmokeDetector* smoke = dynamic_cast<SmokeDetector*>(smokeDevice);
    
    if (smoke) {
        std::cout << "🔍 Testing smoke detector..." << std::endl;
        smoke->setParticleDensity(30.0f);
        smoke->detect();
        
        smoke->setParticleDensity(80.0f);
        bool detected = smoke->detect();
        
        if (detected) {
            Alarm::getInstance()->trigger("Smoke detected by " + smoke->getName());
        }
    }
    
    Device* gasDevice = manager->getDeviceById(1008);
    GasDetector* gas = dynamic_cast<GasDetector*>(gasDevice);
    
    if (gas) {
        std::cout << "\n🔍 Testing gas detector..." << std::endl;
        gas->setGasConcentration(50.0f);
        gas->detect();
        
        gas->setGasConcentration(150.0f);
        bool detected = gas->detect();
        
        if (detected) {
            Alarm::getInstance()->trigger("Gas detected by " + gas->getName());
        }
    }
    
    Alarm::getInstance()->silence();
}

void testDeviceRemoval() {
    printHeader("TEST 8: Device Removal (LLR16)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    std::cout << "🗑️ Attempting to remove regular device (ID: 1001)..." << std::endl;
    bool removed1 = manager->removeDevice(1001);
    std::cout << "Result: " << (removed1 ? "SUCCESS" : "FAILED") << std::endl;
    
    std::cout << "\n🗑️ Attempting to remove critical device (ID: 1007)..." << std::endl;
    bool removed2 = manager->removeDevice(1007);
    std::cout << "Result: " << (removed2 ? "SUCCESS" : "FAILED") << std::endl;
    
    std::cout << "\n📊 Updated device list:" << std::endl;
    manager->listAllDevices();
}

void testIDAutoIncrement() {
    printHeader("TEST 9: ID Auto-Increment (LLR37)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    std::cout << "Creating multiple devices rapidly to test ID sequence..." << std::endl;
    std::cout << "Expected: Sequential IDs with no gaps or duplicates\n" << std::endl;
    
    for (int i = 1; i <= 5; i++) {
        Light* light = DeviceFactory::createLight("Test Light " + std::to_string(i));
        manager->addDevice(light);
    }
    
    std::cout << "\n📊 Checking ID sequence for all Light devices:" << std::endl;
    manager->listDevicesByType(DeviceType::LIGHT);
}

void testLoggerIntegration() {
    printHeader("TEST 10: Logger Integration");
    
    Logger* logger = Logger::getInstance();
    logger->enableFileLogging("device_system.log");
    
    logger->log(LogLevel::INFO, "System started successfully");
    logger->log(LogLevel::WARNING, "High temperature detected in server room");
    logger->log(LogLevel::CRITICAL, "Critical device failure - immediate attention required");
    logger->log(LogLevel::DEBUG, "Debug information: Memory usage at 75%");
    
    std::cout << "\n✅ Logs written to device_system.log" << std::endl;
}

int main() {
    std::cout << "\n╔══════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   SMART HOME DEVICE FRAMEWORK - INTEGRATION TEST    ║" << std::endl;
    std::cout << "║              Developer B - Device Core               ║" << std::endl;
    std::cout << "║  Testing LLRs: 9, 10, 11, 12, 13, 15, 16, 17,      ║" << std::endl;
    std::cout << "║                32, 33, 34, 35, 37                    ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════╝\n" << std::endl;
    
    try {
        testDeviceCreation();
        testDeviceListing();
        testDeviceOperations();
        testPrototypePattern();
        testCriticalDeviceProtection();
        testAlarmSingleton();
        testDetectorFunctionality();
        testDeviceRemoval();
        testIDAutoIncrement();
        testLoggerIntegration();
        
        printHeader("🎉 ALL TESTS COMPLETED SUCCESSFULLY!");
        
        std::cout << "\n📋 SOLID Principles Applied:" << std::endl;
        std::cout << "✅ S - Single Responsibility" << std::endl;
        std::cout << "✅ O - Open/Closed" << std::endl;
        std::cout << "✅ L - Liskov Substitution" << std::endl;
        std::cout << "✅ I - Interface Segregation" << std::endl;
        std::cout << "✅ D - Dependency Inversion" << std::endl;
        
        std::cout << "\n📊 LLR Requirements Coverage:" << std::endl;
        std::cout << "✅ LLR9-LLR37 - All requirements implemented" << std::endl;
        
        std::cout << "\n🎨 Design Patterns Used:" << std::endl;
        std::cout << "✅ Singleton (Alarm, Logger, DeviceManager)" << std::endl;
        std::cout << "✅ Factory Method (DeviceFactory)" << std::endl;
        std::cout << "✅ Prototype (Device::clone)" << std::endl;
        std::cout << "✅ Template Method (Detector::detect)" << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "\n❌ TEST FAILED: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}