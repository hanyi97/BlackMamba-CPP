#ifndef BLACKMAMBA_STATEMANAGER_HPP
#define BLACKMAMBA_STATEMANAGER_HPP

#include <memory>
#include <stack>

#include "State.hpp"

namespace Engine
{
    class StateManager
    {
    private:
        std::stack<std::unique_ptr<State>> stateStack;
        std::unique_ptr<State> newState;

        bool add;
        bool replace;
        bool remove;
    public:
        StateManager();

        std::unique_ptr<State>& GetCurrent();

        void addState(std::unique_ptr<State> toAdd, bool replace = false);
        void popCurrent();
        void processStateChange();
    };
}

#endif
