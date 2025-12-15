#ifndef APPSERVICES_H
#define APPSERVICES_H

#include "core/IAppServices.h"

// Selin modülü (include/ içinde duruyorsa bu şekilde)
#include "mode/ModeManager.h"
#include "mode/MockDeviceManager.h"
#include "mode/Mode.h"

class AppServices : public IAppServices {
public:
    AppServices();

    void showDevices();
    void addDeviceFlow();
    void removeDeviceFlow();
    void changeModeFlow();
    void previousState();
    void simulateScenario();

    void requestStopEventLoop();
    void flushAndCloseLogs();
};

#endif
