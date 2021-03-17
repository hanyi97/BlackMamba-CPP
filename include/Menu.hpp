//
// Created by sheng on 11/3/2021.
//

#ifndef BLACKMAMBA_MENU_HPP
#define BLACKMAMBA_MENU_HPP

#pragma once

#include <memory>

#include  <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.hpp"

#define menuLength 3

namespace Engine {
    class Menu : public Engine::State {
    private:
        std::shared_ptr<Context> context;
        sf::Text gameTitle;
        sf::Text menu[menuLength];
        int currentMenuIndex;
        bool playButtonPressed;
        bool exitButtonPressed;
        bool helpButtonPressed;

    public:
        Menu(std::shared_ptr<Context> &context);

        ~Menu();

        void moveUp();

        void moveDown();

        int pressedItem()
        {
            return currentMenuIndex;
        }

        void init() override;

        void processInput() override;

        void update(sf::Time) override;

        void draw() override;
    };
}

#endif