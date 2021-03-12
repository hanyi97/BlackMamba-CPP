//
// Created by sheng on 11/3/2021.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "../../include/Game.hpp"
#include "../../include/Menu.hpp"
#include "../../include/GamePanel.hpp"

using namespace Engine;

Menu::Menu(std::shared_ptr<Context> &context)
    : context(context), playButtonPressed(false), playButtonSelected(true), exitButtonPressed(false), exitButtonSelected(false)
{

}
Menu::~Menu()
{

}

void Menu::init()
{
    context->assets->addFont(MAIN_FONT, "../assets/fonts/Helvetica.ttf");
    //title
    gameTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameTitle.setString("Black Mamba");
    gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
    gameTitle.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 200.f);
    // Play Button
    playButton.setFont(context->assets->getFont(MAIN_FONT));
    playButton.setString("Play");
    playButton.setOrigin(playButton.getLocalBounds().width / 2, playButton.getLocalBounds().height / 2);
    playButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 - 25.f);
    // Exit Button
    exitButton.setFont(context->assets->getFont(MAIN_FONT));
    exitButton.setString("Quit");
    exitButton.setOrigin(exitButton.getLocalBounds().width / 2, exitButton.getLocalBounds().height / 2);
    exitButton.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2 + 25.f);

}
void Menu::processInput()
{
    sf::Event event;
    while (context->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            context->window->close();
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    if (!playButtonSelected)
                    {
                        playButtonSelected = true;
                        exitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!exitButtonSelected)
                    {
                        playButtonSelected = false;
                        exitButtonSelected = true;
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    playButtonPressed = false;
                    exitButtonPressed = false;
                    if (playButtonSelected)
                    {
                        playButtonPressed = true;
                    }
                    else
                    {
                        exitButtonPressed = true;
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}
void Menu::update(sf::Time)
{
    if (playButtonSelected)
    {
        playButton.setFillColor(sf::Color::Yellow);
        exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        exitButton.setFillColor(sf::Color::Yellow);
        playButton.setFillColor(sf::Color::White);
    }
    if (playButtonPressed)
    {
        context->states->addState(std::make_unique<GamePanel>(context),true);
    }
    else if (exitButtonPressed)
    {
        context->window->close();
    }
}
void Menu::draw()
{
    context->window->clear();
    context->window->draw(gameTitle);
    context->window->draw(playButton);
    context->window->draw(exitButton);
    context->window->display();
}
