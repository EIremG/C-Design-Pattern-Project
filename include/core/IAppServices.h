#ifndef IAPPSERVICES_H
#define IAPPSERVICES_H

#include <iostream>
#include <string>

class IAppServices {
public:
    virtual ~IAppServices() {}

    virtual void showDevices() = 0;
    virtual void addDeviceFlow() = 0;
    virtual void removeDeviceFlow() = 0;
    virtual void changeModeFlow() = 0;
    virtual void previousState() = 0;
    virtual void simulateScenario() = 0;

    virtual void requestStopEventLoop() = 0;
    virtual void flushAndCloseLogs() = 0;
};

class NullAppServices : public IAppServices {
public:
    void showDevices() { info("showDevices"); }
    void addDeviceFlow() { info("addDeviceFlow"); }
    void removeDeviceFlow() { info("removeDeviceFlow"); }
    void changeModeFlow() { info("changeModeFlow"); }
    void previousState() { info("previousState"); }
    void simulateScenario() { info("simulateScenario"); }

    void requestStopEventLoop() { /* no-op */ }
    void flushAndCloseLogs() { /* no-op */ }

private:
    void info(const std::string& name) {
        std::cout << "[INFO] " << name << " is not integrated yet.\n";
    }
};

#endif
