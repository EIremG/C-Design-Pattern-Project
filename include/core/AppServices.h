#ifndef APPSERVICES_H
#define APPSERVICES_H

#include "core/IAppServices.h"

// Selin modülü header'ları (sende include/mode altında olduğu için böyle)
#include "mode/ModeManager.h"
#include "mode/MockDeviceManager.h"

class AppServices : public IAppServices {
public:
    AppServices();

    void showDevices();
    void addDeviceFlow();
    void removeDeviceFlow();
    void changeModeFlow();
    void previousState();      // <-- burası dolacak
    void simulateScenario();

    void requestStopEventLoop();
    void flushAndCloseLogs();

private:
    // Selin modülü state'ini KORUMAK için member tutuyoruz
    MockDeviceManager m_dm;
    ModeManager m_mm;
};

#endif
