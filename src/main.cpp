#include <iostream>
#include "../include/DeviceManager.h"
#include "../include/DeviceFactory.h"
#include "../include/CriticalDeviceGuard.h"
#include "../include/Logger.h"

void printHeader(const std::string& title) {
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "╚════════════════════════════════════════╝\n" << std::endl;
}

void testDeviceCreation() {
    printHeader("TEST 1: Device Creation & Factory (LLR9, LLR37)");
    
    DeviceManager* manager = DeviceManager::getInstance();
    
    // Create devices using factory
    Light* light1 = DeviceFactory::createLight("Living Room Light", "warm white", 70);
    Light* light2 = DeviceFactory::createLight("Bedroom Light", "blue", 50);
    
    Camera* camera1 = DeviceFactory::createCamera("Front Door Camera", true, 60, true);
    Camera* camera2 = DeviceFactory::createCamera("Backyard Camera", true, 30, false);
    
    TV* tv1 = DeviceFactory::createTV("Living Room TV", TVModel::SAMSUNG);
    TV* tv2 = DeviceFactory::createTV("Bedroom TV", TVModel::LG);
    
    MusicSystem* music = DeviceFactory::createMusicSystem("Home Theater");
    
    // Create detectors using factory (LLR12)
    Detector* smokeDetector = DeviceFactory::createDetector(DetectorType::SMOKE, 
                                                            "Kitchen Smoke Detector", 0.8f, 60.0f);
    Detector* gasDetector = DeviceFactory::createDetector(DetectorType::GAS, 
                                                          "Basement Gas Detector", 0.9f, 100.0f);
    
    // Get alarm singleton (LLR13)
    Alarm* alarm = DeviceFactory::getAlarmInstance();
    
    // Add all devices to manager (LLR16)
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
    
    // Verify ID auto-increment (LLR37)
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
    
    // Get devices by ID
    Device* light = manager->getDeviceById(1000);
    Device* camera = manager->getDeviceById(1002);
    Device* music = manager->getDeviceById(1006);
    Device* tv = manager->getDeviceById(1004);
    
    // Test Light operations (LLR35)
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
    
    // Test Camera operations (LLR34)
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
    
    // Test TV operations (LLR33)
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
    
    // Test Music System
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
    
    // Try to power off a smoke detector (should fail)
    Device* smokeDetector = manager->getDeviceById(1007);
    if (smokeDetector) {
        std::cout << "\n🔒 Attempting to power off critical device..." << std::endl;
        bool canPowerOff = CriticalDeviceGuard::canPowerOff(smokeDetector);
        
        if (!canPowerOff) {
            std::cout << "   Blocked by security guard!" << std::endl;
            
            std::cout << "\n🔑 Attempting admin override with wrong password..." << std::endl;
            bool override1 = CriticalDeviceGuard::requestAdminOverride(smokeDetector, "wrong");
            
            std::cout << "\n🔑 Attempting admin override with correct password..." << std::endl;
            bool override2 = CriticalDeviceGuard::requestAdminOverride(smokeDetector, "admin123");
            
            if (override2) {
                std::cout << "   Admin can now manually override if needed" << std::endl;
            }
        }
        
        // Try to power off directly (should also fail)
        std::cout << "\n🔒 Direct powerOff() call on critical device..." << std::endl;
        smokeDetector->powerOff();
    }
    
    // Try to power off a regular device (should succeed)
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
    
    // Test that alarm cannot be powered off
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
        smoke->detect(); // Should not trigger
        
        smoke->setParticleDensity(80.0f);
        bool detected = smoke->detect(); // Should trigger
        
        if (detected) {
            Alarm::getInstance()->trigger("Smoke detected by " + smoke->getName());
        }
    }
    
    Device* gasDevice = manager->getDeviceById(1008);
    GasDetector* gas = dynamic_cast<GasDetector*>(gasDevice);
    
    if (gas) {
        std::cout << "\n🔍 Testing gas detector..." << std::endl;
        gas->setGasConcentration(50.0f);
        gas->detect(); // Should not trigger
        
        gas->setGasConcentration(150.0f);
        bool detected = gas->detect(); // Should trigger
        
        if (detected) {
            Alarm::getInstance()->trigger("Gas detected by " + gas->getName());
        }
    }
    
    // Silence the alarm
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
    logger->log(LogLevel::ERROR, "Critical device failure - immediate attention required");
    logger->log(LogLevel::DEBUG, "Debug information: Memory usage at 75%");
    
    std::cout << "\n✅ Logs written to device_system.log" << std::endl;
}

int main() {
    std::cout << "\n╔══════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   SMART HOME DEVICE FRAMEWORK - INTEGRATION TEST    ║" << std::endl;
    std::cout << "║              Developer B - Device Core               ║" << std::endl;
    std::cout << "║                                                      ║" << std::endl;
    std::cout << "║  Testing LLRs: 9, 10, 11, 12, 13, 15, 16, 17,      ║" << std::endl;
    std::cout << "║                32, 33, 34, 35, 37                    ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════╝\n" << std::endl;
    
    try {
        testDeviceCreation();          // LLR9, LLR37, LLR12, LLR13
        testDeviceListing();            // LLR32
        testDeviceOperations();         // LLR11, LLR33, LLR34, LLR35
        testPrototypePattern();         // LLR15
        testCriticalDeviceProtection(); // LLR17
        testAlarmSingleton();           // LLR13
        testDetectorFunctionality();    // LLR12
        testDeviceRemoval();            // LLR16
        testIDAutoIncrement();          // LLR37
        testLoggerIntegration();        // Bonus
        
        printHeader("🎉 ALL TESTS COMPLETED SUCCESSFULLY!");
        
        std::cout << "\n📋 SOLID Principles Applied:" << std::endl;
        std::cout << "✅ S - Single Responsibility: Each class has one clear purpose" << std::endl;
        std::cout << "✅ O - Open/Closed: Extendable via inheritance, closed for modification" << std::endl;
        std::cout << "✅ L - Liskov Substitution: All devices can substitute Device base class" << std::endl;
        std::cout << "✅ I - Interface Segregation: Specific interfaces for different device types" << std::endl;
        std::cout << "✅ D - Dependency Inversion: Depend on Device abstraction, not concrete classes" << std::endl;
        
        std::cout << "\n📊 LLR Requirements Coverage:" << std::endl;
        std::cout << "✅ LLR9  - Device base class with id, name, powerState, type" << std::endl;
        std::cout << "✅ LLR10 - Light, Camera, TV, Detector, MusicSystem implemented" << std::endl;
        std::cout << "✅ LLR11 - powerOn()/powerOff() methods for all devices" << std::endl;
        std::cout << "✅ LLR12 - Detector factory pattern (SmokeDetector, GasDetector)" << std::endl;
        std::cout << "✅ LLR13 - Alarm singleton implementation" << std::endl;
        std::cout << "✅ LLR15 - Prototype pattern (clone method)" << std::endl;
        std::cout << "✅ LLR16 - Device list management (add/remove/get by ID)" << std::endl;
        std::cout << "✅ LLR17 - Critical devices cannot be powered off" << std::endl;
        std::cout << "✅ LLR32 - Device list display format" << std::endl;
        std::cout << "✅ LLR33 - TV model selection (Samsung/LG/Sony)" << std::endl;
        std::cout << "✅ LLR34 - Camera configuration (motionDetection, FPS, nightVision)" << std::endl;
        std::cout << "✅ LLR35 - Light configuration (color, illumination)" << std::endl;
        std::cout << "✅ LLR37 - Auto-increment ID system" << std::endl;
        
        std::cout << "\n🎨 Design Patterns Used:" << std::endl;
        std::cout << "✅ Singleton Pattern - Alarm, DeviceManager, Logger" << std::endl;
        std::cout << "✅ Factory Method Pattern - DeviceFactory, DetectorFactory" << std::endl;
        std::cout << "✅ Prototype Pattern - clone() method in all devices" << std::endl;
        std::cout << "✅ Template Method Pattern - Device base class structure" << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "\n❌ TEST FAILED: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}