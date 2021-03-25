//
// Created by danial on 24/3/2021.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <windows.h>
#include "../../include/Game.hpp"
#include "../../include/Pause.hpp"
#include "../../include/Menu.hpp"
#include "../../include/GamePanel.hpp"
#include <iostream>

using namespace Engine;

Pause::Pause(std::shared_ptr<Context> &context, int difficulty) : context(context), normalPressed(false), difficulty(difficulty) {

}

Pause::~Pause() {

}

void Pause::init() {
    context->assets->addFont(MAIN_FONT, "../assets/fonts/Helvetica.ttf");
    context->assets->addTexture(0, "../assets/images/pause_screen.jpg", true);


    // snake image
    pause.setTexture(context->assets->getTexture(0));
    pause.setScale(0.4,0.4);
    pause.setPosition(450, 100);

    context->assets->addTexture(2, "../assets/images/reset_button.png", true);
    //Normal button
    rectangle.setTexture(context->assets->getTexture(2));
    rectangle.setScale(0.1,0.1);
    rectangle.setPosition(200,400);

    context->assets->addTexture(3, "../assets/images/pause_exit.png", true);
    exitButton.setTexture(context->assets->getTexture(3));
    exitButton.setScale(0.73,0.73);
    exitButton.setPosition(650,400);

}

void Pause::processInput() {
    // Keyboard menu
    sf::Event event;
    while (context->window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                context->window->close();
                break;
            case sf::Event::MouseMoved:
                std::cout << "X: " << event.mouseMove.x << "Y: " << event.mouseMove.y << std::endl;
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // reset
                    if (event.mouseButton.x >= 300 and event.mouseButton.x <= 450) {
                        if (event.mouseButton.y >= 400 and event.mouseButton.y <= 500)
                            normalPressed = true;
                    }
                    // exit
                    if (event.mouseButton.x >= 700 and event.mouseButton.x <= 800) {
                        if (event.mouseButton.y >= 400 and event.mouseButton.y <= 500)
                            exit(EXIT_SUCCESS);
                    }
                }
                break;
        }
    }
}


void Pause::update(sf::Time) {
    if (normalPressed) {
        context->states->addState(std::make_unique<GamePanel>(context, 0), true);
    }
    if (normalPressed && difficulty == HARD) {
        context->states->addState(std::make_unique<GamePanel>(context, 1), true);
    }
}

void Pause::draw() {
    context->window->clear();
    context->window->draw(pause);
    context->window->draw(gameTitle);
    context->window->draw(rectangle);
    context->window->draw(exitButton);
    context->window->display();
}


