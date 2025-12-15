#include "core/AppServices.h"
#include <iostream>

#include "mode/ModeManager.h"
#include "mode/MockDeviceManager.h"

// Sadece bildirim:
void runModeMenu(ModeManager& modeManager, MockDeviceManager& deviceManager);

AppServices::AppServices() {}

void AppServices::showDevices() { std::cout << "[TODO] showDevices\n"; }
void AppServices::addDeviceFlow() { std::cout << "[TODO] addDeviceFlow\n"; }
void AppServices::removeDeviceFlow() { std::cout << "[TODO] removeDeviceFlow\n"; }
void AppServices::previousState() { std::cout << "[TODO] previousState\n"; }
void AppServices::simulateScenario() { std::cout << "[TODO] simulateScenario\n"; }

void AppServices::changeModeFlow()
{
    MockDeviceManager dm;
    ModeManager mm(dm);
    runModeMenu(mm, dm);
}

void AppServices::requestStopEventLoop() { /* TODO */ }
void AppServices::flushAndCloseLogs() { /* TODO */ }
