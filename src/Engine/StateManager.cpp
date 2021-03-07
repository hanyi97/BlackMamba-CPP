#include "../../include/StateManager.hpp"

using namespace Engine;

StateManager::StateManager() : add(false), replace(false), remove(false)
{

}

StateManager::~StateManager() = default;

void StateManager::Add(std::unique_ptr<State> toAdd, bool replace)
{
    add = true;
    newState = std::move(toAdd);
    this->replace = replace;
}

void StateManager::PopCurrent()
{
    remove = true;
}

void StateManager::ProcessStateChange()
{
    if (remove && !stateStack.empty())
    {
        stateStack.pop();
        if (!stateStack.empty())
        {
            stateStack.top()->Start();
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
            stateStack.top()->Pause();
        }

        stateStack.push(std::move(newState));
        stateStack.top()->Init();
        stateStack.top()->Start();
        add = false;
    }
}

std::unique_ptr<State>& StateManager::GetCurrent()
{
    return stateStack.top();
}