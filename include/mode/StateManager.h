#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>
#include "SystemSnapshot.h"

class StateManager
{
public:
    StateManager();

    void push(const SystemSnapshot& s);
    bool canGoPrevious() const;
    bool popPrevious(SystemSnapshot& out);
    void clear();

private:
    std::vector<SystemSnapshot> m_stack;
};

#endif

