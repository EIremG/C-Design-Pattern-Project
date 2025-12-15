#include <mode/ModeManager.h>


ModeManager::ModeManager(IDeviceManager& deviceManager)
    : m_devices(deviceManager),
    m_currentMode(MODE_NORMAL)
{
    initDefaultMapping();

    // Camera (3) ve Smoke/Gas (4) HER ZAMAN AÇIK
    m_devices.setPower(3, true);
    m_devices.setPower(4, true);
}

Mode ModeManager::getCurrentMode() const
{
    return m_currentMode;
}


void ModeManager::setMode(Mode newMode)
{
    if (newMode == m_currentMode)
        return;

    // Önce mevcut durumu kaydet (previous için)
    m_stateManager.push(captureSnapshot());

    applyMode(newMode);
    m_currentMode = newMode;
}

bool ModeManager::previousState()
{
    SystemSnapshot prev;
    if (!m_stateManager.popPrevious(prev))
        return false;

    restoreSnapshot(prev);
    return true;
}

SystemSnapshot ModeManager::captureSnapshot() const
{
    SystemSnapshot s;
    s.mode = m_currentMode;

    std::vector<int> ids = m_devices.getAllDeviceIds();
    for (int id : ids)
    {
        s.devicePower[id] = m_devices.getPower(id);
    }

    return s;
}

void ModeManager::restoreSnapshot(const SystemSnapshot& s)
{
    for (auto it = s.devicePower.begin(); it != s.devicePower.end(); ++it)
    {
        m_devices.setPower(it->first, it->second);
    }

    m_currentMode = s.mode;
}

void ModeManager::applyMode(Mode m)
{
    auto it = m_mapping.find(m);
    if (it == m_mapping.end())
        return;

    const std::vector<Action>& actions = it->second;
    for (const Action& a : actions)
    {
        m_devices.setPower(a.deviceId, a.turnOn);
    }

    // Güvenlik cihazlarý HER ZAMAN ON
    m_devices.setPower(3, true); // Camera
    m_devices.setPower(4, true); // Smoke/Gas
}


void ModeManager::initDefaultMapping()
{
    // 1 = Light1
    // 2 = Light2
    // 3 = Camera (always ON)
    // 4 = Smoke/Gas (always ON)

    // NORMAL
    {
        std::vector<Action> v;
        v.push_back(Action(1, true));
        v.push_back(Action(2, true));
        m_mapping[MODE_NORMAL] = v;
    }

    // EVENING
    {
        std::vector<Action> v;
        v.push_back(Action(1, true));
        v.push_back(Action(2, false));
        m_mapping[MODE_EVENING] = v;
    }

    // PARTY
    {
        std::vector<Action> v;
        v.push_back(Action(1, true));
        v.push_back(Action(2, false));
        m_mapping[MODE_PARTY] = v;
    }

    // CINEMA
    {
        std::vector<Action> v;
        v.push_back(Action(1, false));
        v.push_back(Action(2, false));
        m_mapping[MODE_CINEMA] = v;
    }
}
