//
// Created by sheng on 11/3/2021.
// updated by Danial on 17/3/2021.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
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
    context->assets->addTexture(0, "../assets/images/mamba.png", true);
    context->assets->addTexture(1, "../assets/images/king_cobra.png", true);


    // snake image
    snake.setTexture(context->assets->getTexture(0));
    snake.setPosition(385, 100);


    //cobras
    cobra1.setTexture(context->assets->getTexture(1));
    cobra1.setScale(0.2,0.2);
    cobra1.setPosition(190,100);

    cobra2.setTexture(context->assets->getTexture(1));
    cobra2.setScale(0.2,0.2);
    cobra2.setPosition(810,99);

    context->assets->addTexture(2, "../assets/images/start_button.png", true);

    //start button
    start_button.setTexture(context->assets->getTexture(2));
    start_button.setPosition(260,400);

    //help_button
    context->assets->addTexture(3, "../assets/images/help_button.png", true);
    help_button.setTexture(context->assets->getTexture(3));
    help_button.setPosition(480,400);


    //gear_button
    context->assets->addTexture(4, "../assets/images/gear.png", true);
    gear_button.setTexture(context->assets->getTexture(4));
    gear_button.setScale(0.1,0.1);
    gear_button.setPosition(1050,560);


    //exit_button
    context->assets->addTexture(5, "../assets/images/exit_button.png", true);
    exit_button.setTexture(context->assets->getTexture(5));
    exit_button.setPosition(710,400);


    //title
    gameTitle.setFont(context->assets->getFont(MAIN_FONT));
    //gameTitle.setString("Black Mamba");
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
                    // play
                    if (event.mouseButton.x >= 550 and event.mouseButton.x <= 600) {
                        if (event.mouseButton.y >= 305 and event.mouseButton.y <= 325)
                            playButtonPressed = true;
                    }
                    // help
                    if (event.mouseButton.x >= 550 and event.mouseButton.x <= 600) {
                        if (event.mouseButton.y >= 355 and event.mouseButton.y <= 375)
                            helpButtonPressed = true;
                    }
                    // quit
                    if (event.mouseButton.x >= 550 and event.mouseButton.x <= 600) {
                        if (event.mouseButton.y >= 410 and event.mouseButton.y <= 430)
                            exitButtonPressed = true;
                    }
                }
                break;
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
                                std::cout << "Exit button pressed" << std::endl;
                                break;
                        }
                        break;
                    }
                }
                break;
        }
    }
}


void Menu::update(sf::Time) {
    menu[currentMenuIndex].setFillColor(sf::Color::Yellow);
    if (playButtonPressed) {
        context->states->addState(std::make_unique<GamePanel>(context), true);
    } else if (helpButtonPressed) {
        context->states->addState(std::make_unique<Help>(context), true);
    } else if (exitButtonPressed) {
        context->window->close();
    }
}


void Menu::draw() {
    context->window->clear();
    context->window->draw(snake);
    context->window->draw(cobra1);
    context->window->draw(cobra2);
    context->window->draw(gameTitle);
    context->window->draw(start_button);
    context->window->draw(help_button);
    context->window->draw(gear_button);
    context->window->draw(exit_button);
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