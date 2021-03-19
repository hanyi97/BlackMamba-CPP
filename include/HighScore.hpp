//
// Created by gohts on 14/3/2021.
//
/*

#pragma once

#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Food.hpp"
#include "Player.hpp"
#ifndef BLACKMAMBA_HIGHSCORE_H
#define BLACKMAMBA_HIGHSCORE_H
namespace Engine
{
    class GamePanel : public State
    {
    private:
        std::shared_ptr<Context> context;
        sf::Time elapsedTime;
        sf::Sprite background;
        sf::RectangleShape panel;
        sf::RectangleShape divider;
        sf::RectangleShape borders;

        Player player1;
        Player player2;

        bool running;
        int ticks;
    public:
        GamePanel(std::shared_ptr<Context> &);
        ~GamePanel();

        void init() override;
        void processInput() override;
        void update(sf::Time) override;
        void draw() override;
        void pause() override;
        void start() override;
        void drawGrid();
        void showGameOverScreen();
        void showP1LoseScreen();
        void showP2LoseScreen();
        void displayPanelText();
    };
}

#endif //BLACKMAMBA_HIGHSCORE_H
*/