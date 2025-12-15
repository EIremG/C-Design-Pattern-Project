#include "core/AppServices.h"
#include "core/Console.h"

#include "sim/DebugSimulator.h"
#include "sim/EventQueue.h"


#include "ui/DeviceUI.h"
#include "ui/HelpPages.h"
#include "ui/Input.h"

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
    Logger::getInstance()->log("[UI] showDevices selected");
    std::cout << "\n--- DEVICES ---\n";

    // Dev B gelene kadar placeholder
    std::cout << "[INFO] Device list will be provided by DevB(DeviceManager).\n";
    std::cout << "Example:\n";
    std::cout << " - (id=1) Light  status=ON  color=white  illum=70\n";
    std::cout << " - (id=2) TV     status=OFF model=Samsung\n διαφο\n";

    // İstersen burada DevC’nin LLR32 formatına benzer çıktıyı basarız.
}

void AppServices::addDeviceFlow()
{
    Logger::getInstance()->log("[UI] addDeviceFlow selected");

    DeviceAddRequest req = DeviceUI::promptAddRequest();

    Logger::getInstance()->log("[UI] addDeviceFlow request captured");

    std::cout << "\n[ADD] Request captured.\n";
    std::cout << "Type=" << (int)req.type << ", Name=" << req.name << "\n";

    if (req.cloneFromExisting) {
        std::cout << "Clone from device id=" << req.cloneSourceId << "\n";
    }

    if (req.type == UI_LIGHT) {
        std::cout << "Light color=" << req.lightColor
            << ", illum=" << req.lightIllumination << "\n";
    }
    else if (req.type == UI_TV) {
        std::cout << "TV model=" << req.tvModel << "\n";
    }

    std::cout << "\n[INFO] Actual creation will be done by DevB(DeviceFactory/DeviceManager) and DevC(Light/TV).\n";
}

void AppServices::removeDeviceFlow()
{
    Logger::getInstance()->log("[UI] removeDeviceFlow selected");

    int id = DeviceUI::promptRemoveId();

    std::cout << "\n[REMOVE] Device id captured: " << id << "\n";
    std::cout << "[INFO] Actual removal will be done by DevB(DeviceManager::removeDevice).\n";

    Logger::getInstance()->log("[UI] removeDeviceFlow id captured");
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
