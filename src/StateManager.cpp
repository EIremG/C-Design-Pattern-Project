#include "StateManager.h"

StateManager::StateManager() {}

void StateManager::push(const SystemSnapshot& s)
{
    m_stack.push_back(s);
}

bool StateManager::canGoPrevious() const
{
    return !m_stack.empty();
}

bool StateManager::popPrevious(SystemSnapshot& out)
{
    if (m_stack.empty())
        return false;

    out = m_stack.back();
    m_stack.pop_back();
    return true;
}

void StateManager::clear()
{
    m_stack.clear();
}
