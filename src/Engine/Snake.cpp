#include <iostream>
#include "../../include/Snake.hpp"
#include "../../include/Settings.hpp"
#include "../../include/Player.hpp"
#include "../../include/SnakeMath.hpp"

using namespace Engine;
using namespace Math;

Snake::Snake()
{

}

Snake::Snake(std::shared_ptr<Context> &context, int player) :context(context), player(player)
{
}

void Snake::init()
{
    int x, y;
    switch (player)
    {
        case PLAYER1:
            x = SnakeMath::calculateSnake1X(Settings::UNIT_SIZE);
            y = SnakeMath::calculateSnake1Y(Settings::GAME_YPOS, Settings::UNIT_SIZE);
            break;
        case PLAYER2:
            x = SnakeMath::calculateSnake2X(Settings::CENTER, Settings::UNIT_SIZE);
            y = SnakeMath::calculateSnake2Y(Settings::GAME_YPOS, Settings::UNIT_SIZE);
            break;
        default:
            x = 0, y = 0;
            break;
    }
    xPos = x;
    yPos = y;
}

void Snake::move()
{
    body.emplace_back(context, xPos, yPos);
    if (body.size() > size) body.erase(body.begin());
}

void Snake::draw(char dir)
{
    for (auto part = body.begin(); part != body.end(); ++part)
    {
        if (part == body.end()-1)
            part->drawHead(dir);
        else
            part->drawBody();
    }
}

void Snake::setXPos(int x)
{
    xPos = x;
}

int Snake::getXPos() const
{
    return xPos;
}

void Snake::setYPos(int y)
{
    yPos = y;
}

int Snake::getYPos() const
{
    return yPos;
}
