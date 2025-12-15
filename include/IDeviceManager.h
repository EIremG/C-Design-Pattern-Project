#ifndef I_DEVICE_MANAGER_H
#define I_DEVICE_MANAGER_H

#include <vector>

class IDeviceManager
{
public:
    virtual ~IDeviceManager() {}

    virtual std::vector<int> getAllDeviceIds() const = 0;
    virtual bool getPower(int deviceId) const = 0;
    virtual void setPower(int deviceId, bool on) = 0;
};

#endif
