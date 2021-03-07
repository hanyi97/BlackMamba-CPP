#include "../../include/Player.hpp"
#include "../../include/GameMath.hpp"
#include "../../include/Settings.hpp"

using namespace Engine;
using namespace Math;

Player::Player(std::shared_ptr<Context> &context, int player) //: food(context, GameMath::getRandomLeftX(Settings::CENTER, Settings::UNIT_SIZE),
                                                                     //GameMath::getRandomY(Settings::GAME_YPOS, Settings::GAME_HEIGHT, Settings::UNIT_SIZE))
{
    switch (player)
    {
        case PLAYER1:
            this->food = Food(context, GameMath::getRandomLeftX(Settings::CENTER, Settings::UNIT_SIZE),
                     GameMath::getRandomY(Settings::GAME_YPOS, Settings::GAME_HEIGHT, Settings::UNIT_SIZE));
            break;
        case PLAYER2:
            this->food = Food(context, GameMath::getRandomRightX(Settings::CENTER, Settings::UNIT_SIZE),
                      GameMath::getRandomY(Settings::GAME_YPOS, Settings::GAME_HEIGHT, Settings::UNIT_SIZE));
            break;
        default:
            break;
    }

}

void Player::draw()
{
    food.draw();
}