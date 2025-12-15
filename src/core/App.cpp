#include "core/App.h"
#include "core/IAppServices.h"
#include "core/MenuController.h"
#include "core/Input.h"
#include "core/SignalFlag.h"

#include <iostream>

App::App(IAppServices& services, MenuController& menu)
    : m_services(services), m_menu(menu) {
}

void App::doShutdown() {
    m_services.requestStopEventLoop();
    m_services.flushAndCloseLogs();
}

int App::run() {
    SignalFlag::install();

    bool running = true;
    while (running && !SignalFlag::shouldStop()) {
        m_menu.showMainMenu();

        int choice = Input::readIntInRange("Select (1-7): ", 1, 7);
        switch (choice) {
        case 1: m_services.showDevices(); break;
        case 2: m_services.addDeviceFlow(); break;
        case 3: m_services.removeDeviceFlow(); break;
        case 4: m_services.changeModeFlow(); break;
        case 5: m_services.previousState(); break;
        case 6: m_services.simulateScenario(); break;
        case 7: running = false; break;
        default: std::cout << "[ERROR] Unexpected choice.\n"; break;
        }

        if (running) {
            m_menu.showAfterActionPause();
            std::string dummy;
            Input::readLine(dummy);
        }
    }

    doShutdown();
    return 0;
}
