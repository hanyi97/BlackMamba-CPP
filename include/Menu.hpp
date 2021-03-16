//
// Created by sheng on 11/3/2021.
//

#pragma once

#include <memory>

#include  <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace Engine {
    class Menu : public Engine::State {
    private:
        std::shared_ptr<Context> context;
        sf::Text gameTitle;
        sf::Text playButton;
        sf::Text exitButton;

        sf::Sprite snake;
        sf::Sprite cobra1;
        sf::Sprite cobra2;


        //buttons
        sf::Sprite start_button;
        sf::Sprite help_button;
        sf::Sprite gear_button;
        sf::Sprite exit_button;

        bool playButtonSelected;
        bool playButtonPressed;

        bool exitButtonSelected;
        bool exitButtonPressed;

    public:
        Menu(std::shared_ptr<Context> &context);

        ~Menu();

        void init() override;

        void processInput() override;

        void update(sf::Time) override;

        void draw() override;
    };
}