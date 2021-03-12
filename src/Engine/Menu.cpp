//
// Created by sheng on 11/3/2021.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "../../include/Game.hpp"
#include "../../include/Menu.hpp"
#include "../../include/Help.hpp"
#include "../../include/GamePanel.hpp"

#include <iostream>

using namespace Engine;

Menu::Menu(std::shared_ptr<Context> &context)
        : context(context), playButtonPressed(false), exitButtonPressed(false), helpButtonPressed(false) {

}

Menu::~Menu() {

}

void Menu::init() {
    context->assets->addFont(MAIN_FONT, "../assets/fonts/Helvetica.ttf");
    //title
    gameTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameTitle.setString("Black Mamba");
    gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
    gameTitle.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 200.f);

    // Play Button
    menu[0].setFont(context->assets->getFont(MAIN_FONT));
    menu[0].setString("Play");
    menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
    menu[0].setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 25.f);

    // Help Button
    menu[1].setFont(context->assets->getFont(MAIN_FONT));
    menu[1].setString("Help");
    menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
    menu[1].setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 + 25.f);

    // Exit Button
    menu[2].setFont(context->assets->getFont(MAIN_FONT));
    menu[2].setString("Quit");
    menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
    menu[2].setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 + 75.f);

}

void Menu::processInput() {
    sf::Event event;
    while (context->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            context->window->close();
        else {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            moveUp();
                            break;
                        case sf::Keyboard::Down:
                            moveDown();
                            break;
                        case sf::Keyboard::Return: {
                            playButtonPressed = false;
                            exitButtonPressed = false;
                            helpButtonPressed = false;
                            switch (pressedItem()) {
                                case 0:
                                    playButtonPressed = true;
                                    std::cout << "Play button pressed" << std::endl;
                                    break;

                                case 1:
                                    helpButtonPressed = true;
                                    std::cout << "Help button pressed" << std::endl;
                                    break;
                                case 2:
                                    exitButtonPressed = true;
                                    context->window->close();
                                    std::cout << "Exit button pressed" << std::endl;
                                    break;
                            }
                        }
                    }
            }
        }
    }
}

void Menu::update(sf::Time) {
    menu[currentMenuIndex].setFillColor(sf::Color::Yellow);
    if (playButtonPressed) {
        context->states->addState(std::make_unique<GamePanel>(context), true);
    } else if (helpButtonPressed) {
        context->states->addState(std::make_unique<Help>(context), true);
    }
//    else
//    {
//        context->window->close();
//    }
}

void Menu::draw() {
    context->window->clear();
    context->window->draw(gameTitle);
    context->window->draw(menu[0]);
    context->window->draw(menu[1]);
    context->window->draw(menu[2]);
    context->window->display();
}

void Menu::moveUp() {
    if (currentMenuIndex - 1 >= 0) {
        menu[currentMenuIndex].setFillColor(sf::Color::White);
        currentMenuIndex--;
        menu[currentMenuIndex].setFillColor(sf::Color::Yellow);
    }
}

void Menu::moveDown() {
    if (currentMenuIndex + 1 < menuLength) {
        menu[currentMenuIndex].setFillColor(sf::Color::White);
        currentMenuIndex++;
        menu[currentMenuIndex].setFillColor(sf::Color::Yellow);
    }
}