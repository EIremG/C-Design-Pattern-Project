#include "core/AppServices.h"
#include "core/Console.h"

#include "sim/DebugSimulator.h"
#include "sim/EventQueue.h"


#include "ui/DeviceUI.h"
#include "ui/HelpPages.h"

#include "devices/HomeDeviceManager.h"
#include "devices/DeviceFactory.h"
#include "ui/DeviceUI.h"

#include "log/Logger.h"
#include "log/LogFormatterFactory.h"
#include "log/NotificationManager.h"

#include <iostream>

// ModeMenu.cpp içinde tanımlı fonksiyon:
void runModeMenu(ModeManager& modeManager, MockDeviceManager& deviceManager);
void runAlarmDemoScenario();

AppServices::AppServices()
    : m_dm(), m_mm(m_dm)   // ModeManager device manager ref istiyor
{
    LogFormatter* fmt = LogFormatterFactory::createFormatter("json");
    Logger::getInstance()->initialize("msh.log", fmt);
    Logger::getInstance()->log("[BOOT] AppServices initialized");
}


void AppServices::showDevices()
{
    Logger::getInstance()->log("[UI] showDevices");

    std::cout << "\n--- DEVICES ---\n";
    HomeDeviceManager::getInstance()->listAllDevices();
}

void AppServices::addDeviceFlow()
{
    Logger::getInstance()->log("[UI] addDeviceFlow");

    DeviceAddRequest req = DeviceUI::promptAddRequest();

    HomeDeviceManager* mgr = HomeDeviceManager::getInstance();

    // 1) Clone ile ekleme
    if (req.cloneFromExisting) {
        HomeDevice* src = mgr->getDeviceById(req.cloneSourceId);
        if (!src) {
            std::cout << "[ERROR] Source device not found.\n";
            return;
        }
        HomeDevice* copy = src->clone();
        mgr->addDevice(copy);
        std::cout << "[OK] Device cloned and added. New id=" << copy->getId() << "\n";
        Logger::getInstance()->log("[UI] addDeviceFlow cloned");
        return;
    }

    // 2) Normal create ile ekleme
    HomeDevice* created = 0;

    switch (req.type)
    {
    case UI_LIGHT:
        created = DeviceFactory::createLight(req.name, req.lightColor, req.lightIllumination);
        break;

    case UI_TV:
        // req.tvModel: 1=Samsung, 2=LG (senin UI’dan)
        created = DeviceFactory::createTV(req.name, req.tvModel);
        break;

    case UI_CAMERA:
        created = DeviceFactory::createCamera(req.name, false, 30, false);
        break;

    case UI_SMOKE_DETECTOR:
        // typeCode için: çoğu implementasyonda 0=smoke, 1=gas olur.
        // Eğer sizde farklıysa DetectorFactory.cpp’den bakıp bu iki sayıyı değiştiririz.
        created = DeviceFactory::createDetector(0, req.name, 70.0f, 10.0f);
        break;

    case UI_GAS_DETECTOR:
        created = DeviceFactory::createDetector(1, req.name, 70.0f, 10.0f);
        break;

    default:
        std::cout << "[ERROR] Unknown device type.\n";
        return;
    }

    if (!created) {
        std::cout << "[ERROR] DeviceFactory returned null.\n";
        return;
    }

    mgr->addDevice(created);
    std::cout << "[OK] Device added. id=" << created->getId() << "\n";
    Logger::getInstance()->log("[UI] addDeviceFlow OK");
}


void AppServices::removeDeviceFlow()
{
    Logger::getInstance()->log("[UI] removeDeviceFlow");

    int id = DeviceUI::promptRemoveId();

    bool ok = HomeDeviceManager::getInstance()->removeDevice(id);
    if (ok) {
        std::cout << "[OK] Device removed.\n";
        Logger::getInstance()->log("[UI] removeDeviceFlow OK");
    }
    else {
        std::cout << "[WARN] Device not found.\n";
        Logger::getInstance()->log("[UI] removeDeviceFlow NOT_FOUND");
    }
}

void AppServices::changeModeFlow()
{
    runModeMenu(m_mm, m_dm);
}

void AppServices::previousState()
{
    if (!m_mm.previousState())
        std::cout << "No previous state!\n";

    m_dm.printStatus();
}

void AppServices::simulateScenario()
{
    Logger::getInstance()->log("[SIM] Scenario started");
    std::cout << "\n[Sim] Creating demo events...\n";

    DebugSimulator sim;

    Logger::getInstance()->log("[SIM] enqueue MotionEvent(camera=1)");
    sim.simulateMotion(1);

    Logger::getInstance()->log("[SIM] enqueue AlarmEvent(detector=1)");
    sim.simulateAlarm(1);

    // Dev G: notification (alarm olayı için)
    // NOT: Eğer NotificationManager() private çıkarsa alttaki “3) Eğer burada compile hatası alırsan” bölümüne bak.
    NotificationManager nm;
    nm.notify("ALARM triggered (detector=1)");

    Logger::getInstance()->log("[SIM] enqueue DeviceFailureEvent(device=1)");
    sim.simulateDeviceFailure(1);

    std::cout << "\n[Sim] Processing queued events...\n";
    Logger::getInstance()->log("[SIM] processing 3 queued events");

    EventQueue* q = &EventQueue::getInstance();
    q->processNext();
    q->processNext();
    q->processNext();

    // Dev E demo
    Logger::getInstance()->log("[SIM] running DevE alarm demo scenario");
    runAlarmDemoScenario();

    Logger::getInstance()->log("[SIM] Scenario finished");
    std::cout << "\n[Sim] Done.\n";
}



void AppServices::requestStopEventLoop() { /* TODO */ }
void AppServices::flushAndCloseLogs() 
{
    Logger::getInstance()->log("[SHUTDOWN] closing log");
    Logger::getInstance()->close();
}
