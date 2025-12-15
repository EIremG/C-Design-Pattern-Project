#include "core/AppServices.h"
#include "core/Console.h"
#include "sim/DebugSimulator.h"
#include "sim/EventQueue.h"
#include <iostream>

#include "log/Logger.h"
#include "log/LogFormatterFactory.h"
#include "log/NotificationManager.h"


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


void AppServices::showDevices() { std::cout << "[TODO] showDevices\n"; }
void AppServices::addDeviceFlow() { std::cout << "[TODO] addDeviceFlow\n"; }
void AppServices::removeDeviceFlow() { std::cout << "[TODO] removeDeviceFlow\n"; }

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
