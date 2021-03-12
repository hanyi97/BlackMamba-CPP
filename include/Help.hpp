//
// Created by sheng on 11/3/2021.
//

#pragma once

#include <memory>

#include  <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace Engine {
    class Help : public Engine::State {
    private:
        std::shared_ptr<Context> context;
        sf::Text gameTitle;
        sf::Text t1;
        sf::Text t2;
        sf::Text t3;
        sf::Text t4;
        sf::Text t5;
        sf::Text t6;
        sf::Text backButton;
        sf::Sprite background;

        bool backButtonPressed;


    public:
        Help(std::shared_ptr<Context> &context);

        ~Help();

        void init() override;

        void processInput() override;

        void update(sf::Time) override;

        void draw() override;
    };
}