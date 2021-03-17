#ifndef BLACKMAMBA_STATE_HPP
#define BLACKMAMBA_STATE_HPP
#pragma once
#include <SFML/System/Time.hpp>

namespace Engine
{
    class State
    {
    public:
//        State();
//        virtual ~State();

        virtual void init() = 0;
        virtual void processInput() = 0;
        virtual void update(sf::Time) = 0;
        virtual void draw() = 0;

        virtual void pause(){};
        virtual void start(){};
    };
}
#endif //BLACKMAMBA_STATE_HPP
