#ifndef BLACKMAMBA_MENU_HPP
#define BLACKMAMBA_MENU_HPP

#include <memory>
#include  <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

#define MENU_LENGTH 3

namespace Engine
{
    class Menu : public Engine::State
    {
    private:
        std::shared_ptr<Context> context;
        sf::Text gameTitle;
        sf::Sprite snake;
        sf::Sprite cobra1;
        sf::Sprite cobra2;

        sf::Sprite start_button;
        sf::Sprite help_button;
        sf::Sprite switch_button;
        sf::Sprite exit_button;
        sf::Sprite sound_button;

        sf::Text menu[MENU_LENGTH];

        int currentMenuIndex;
        bool playButtonPressed;
        bool exitButtonPressed;
        bool helpButtonPressed;
        bool onButtonPressed;
        bool offButtonPressed;
        bool bgmCheck = true;

    public:
        Menu(std::shared_ptr<Context> &context);
        ~Menu();

        void moveUp();
        void moveDown();
        void init() override;
        void processInput() override;
        void update(sf::Time) override;
        void draw() override;

        int pressedItem()
        {
            return currentMenuIndex;
        }
    };
}

#endif