#include "core/AppServices.h"
#include <iostream>

// ModeMenu.cpp içinde tanımlı fonksiyon:
void runModeMenu(ModeManager& modeManager, MockDeviceManager& deviceManager);

AppServices::AppServices()
    : m_dm(), m_mm(m_dm)   // ModeManager device manager ref istiyor
{
}

void AppServices::showDevices() { std::cout << "[TODO] showDevices\n"; }
void AppServices::addDeviceFlow() { std::cout << "[TODO] addDeviceFlow\n"; }
void AppServices::removeDeviceFlow() { std::cout << "[TODO] removeDeviceFlow\n"; }
void AppServices::simulateScenario() { std::cout << "[TODO] simulateScenario\n"; }

void AppServices::changeModeFlow()
{
    // Selin'in alt menüsü açılır; m_mm geçmiş state’leri tutmaya devam eder
    runModeMenu(m_mm, m_dm);
}

void AppServices::previousState()
{
    if (!m_mm.previousState())
        std::cout << "No previous state!\n";

    // Selin demo'daki gibi durum bas
    m_dm.printStatus();
}

void AppServices::requestStopEventLoop() { /* TODO */ }
void AppServices::flushAndCloseLogs() { /* TODO */ }
