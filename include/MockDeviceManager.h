#include "IDeviceManager.h"
#include <map>
#include <vector>
#include <iostream>

class MockDeviceManager : public IDeviceManager
{
private:
    std::map<int, bool> m_power;

public:
    MockDeviceManager()
    {
        // 4 device var
        m_power[1] = false;
        m_power[2] = false;
        m_power[3] = false;
        m_power[4] = false;
    }

    void setPower(int deviceId, bool on) override
    {
        m_power[deviceId] = on;
    }

    bool getPower(int deviceId) const override
    {
        auto it = m_power.find(deviceId);
        if (it == m_power.end())
            return false;
        return it->second;
    }

    std::vector<int> getAllDeviceIds() const override
    {
        return { 1, 2, 3, 4 };
    }

    void printStatus() const
    {
        std::cout << "Devices: ";
        for (auto& p : m_power)
        {
            std::cout << p.first << "=" << (p.second ? "ON " : "OFF ");
        }
        std::cout << std::endl;
    }
};
#pragma once
