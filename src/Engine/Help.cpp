//
// Created by sheng on 11/3/2021.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "../../include/Game.hpp"
#include "../../include/Help.hpp"
#include "../../include/Menu.hpp"
#include "../../include/GamePanel.hpp"

#include <iostream>

using namespace Engine;

Help::Help(std::shared_ptr<Context> &context): context(context), backButtonPressed(false){

}

Help::~Help() {

}

void Help::init() {
    context->assets->addTexture(BACKGROUND, "../assets/images/help.png", true);
    context->assets->addFont(MAIN_FONT, "../assets/fonts/Helvetica.ttf");
    background.setTexture(context->assets->getTexture(BACKGROUND));
    background.setPosition(-30,0);
    //title
    gameTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameTitle.setString("Help");
    gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
    gameTitle.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 200.f);

    // Instructions
    t1.setFont(context->assets->getFont(MAIN_FONT));
    t1.setString("Instructions:");
    t1.setOrigin(t1.getLocalBounds().width / 2, t1.getLocalBounds().height / 2);
    t1.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 140.f);

    t2.setFont(context->assets->getFont(MAIN_FONT));
    t2.setString("Eat as many basketballs as you can and avoid obstacles!");
    t2.setOrigin(t2.getLocalBounds().width / 2, t2.getLocalBounds().height / 2);
    t2.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 110.f);

    t3.setFont(context->assets->getFont(MAIN_FONT));
    t3.setString("W - Move Up");
    t3.setOrigin(t3.getLocalBounds().width / 2, t3.getLocalBounds().height / 2);
    t3.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 80.f);

    t4.setFont(context->assets->getFont(MAIN_FONT));
    t4.setString("A - Move Left");
    t4.setOrigin(t4.getLocalBounds().width / 2, t4.getLocalBounds().height / 2);
    t4.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 50.f);

    t5.setFont(context->assets->getFont(MAIN_FONT));
    t5.setString("S - Move Down");
    t5.setOrigin(t5.getLocalBounds().width / 2, t5.getLocalBounds().height / 2);
    t5.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 20.f);

    t6.setFont(context->assets->getFont(MAIN_FONT));
    t6.setString("D - Move Right");
    t6.setOrigin(t6.getLocalBounds().width / 2, t6.getLocalBounds().height / 2);
    t6.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 + 10.f);

    // Back Button
    backButton.setFont(context->assets->getFont(MAIN_FONT));
    backButton.setString("Back");
    backButton.setOrigin(backButton.getLocalBounds().width / 2, backButton.getLocalBounds().height / 2);
    backButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 + 200.f);

}

void Help::processInput() {
    sf::Event event;
    while (context->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            context->window->close();
        else {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Return: {
                            context->states->addState(std::make_unique<Menu>(context), true);
                            break;
                        }
                    }
            }
        }
    }
}

void Help::update(sf::Time) {

}

void Help::draw() {
    context->window->clear();
    context->window->draw(background);
    context->window->draw(backButton);
    context->window->display();
}
