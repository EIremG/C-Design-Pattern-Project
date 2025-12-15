#include "core/AppServices.h"
#include "core/Console.h"
#include "sim/DebugSimulator.h"
#include "sim/EventQueue.h"
#include <iostream>

// ModeMenu.cpp içinde tanımlı fonksiyon:
void runModeMenu(ModeManager& modeManager, MockDeviceManager& deviceManager);
void runAlarmDemoScenario();

AppServices::AppServices()
    : m_dm(), m_mm(m_dm)   // ModeManager device manager ref istiyor
{
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
    std::cout << "\n[Sim] Creating demo events...\n";

    DebugSimulator sim;
    sim.simulateMotion(1);
    sim.simulateAlarm(1);
    sim.simulateDeviceFailure(1);

    std::cout << "\n[Sim] Processing queued events...\n";
    EventQueue* q = &EventQueue::getInstance();
    q->processNext();
    q->processNext();
    q->processNext();

    // Dev E (Alarm/Detector) demo
    runAlarmDemoScenario();

    std::cout << "\n[Sim] Done.\n";
}



void AppServices::requestStopEventLoop() { /* TODO */ }
void AppServices::flushAndCloseLogs() { /* TODO */ }
