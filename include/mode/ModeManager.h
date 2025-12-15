#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <map>
#include <vector>
#include "Mode.h"
#include "StateManager.h"
#include "IDeviceManager.h"

class ModeManager
{
public:
    explicit ModeManager(IDeviceManager& deviceManager);

    Mode getCurrentMode() const;
    void setMode(Mode newMode);
    bool previousState();

private:
    struct Action
    {
        int deviceId;
        bool turnOn;
        Action() : deviceId(0), turnOn(false) {}
        Action(int id, bool on) : deviceId(id), turnOn(on) {}
    };

    void initDefaultMapping();
    void applyMode(Mode m);

    SystemSnapshot captureSnapshot() const;
    void restoreSnapshot(const SystemSnapshot& s);

private:
    IDeviceManager& m_devices;
    StateManager m_stateManager;
    Mode m_currentMode;

    std::map<Mode, std::vector<Action> > m_mapping;
};

#endif

