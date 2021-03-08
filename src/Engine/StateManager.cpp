#include "../../include/StateManager.hpp"

using namespace Engine;

StateManager::StateManager() : add(false), replace(false), remove(false)
{

}

StateManager::~StateManager() = default;

void StateManager::addState(std::unique_ptr<State> toAdd, bool replace)
{
    add = true;
    newState = std::move(toAdd);
    this->replace = replace;
}

void StateManager::popCurrent()
{
    remove = true;
}

void StateManager::processStateChange()
{
    if (remove && !stateStack.empty())
    {
        stateStack.pop();
        if (!stateStack.empty())
        {
            stateStack.top()->start();
        }

        remove = false;
    }

    if (add)
    {
        if (replace && !stateStack.empty())
        {
            stateStack.pop();
            replace = false;
        }

        if (!stateStack.empty())
        {
            stateStack.top()->pause();
        }

        stateStack.push(std::move(newState));
        stateStack.top()->init();
        stateStack.top()->start();
        add = false;
    }
}

std::unique_ptr<State>& StateManager::GetCurrent()
{
    return stateStack.top();
}