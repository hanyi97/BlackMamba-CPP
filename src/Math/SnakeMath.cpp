#include "../../include/SnakeMath.hpp"

using namespace Math;

/**
 * Calculate the starting x position of snake 1
 *
 * @param unitSize: Size of unit
 * @return Snake 1 starting x position
 */
int SnakeMath::calculateSnake1X(int unitSize)
{
    return 5 * unitSize;
}

/**
 * Calculate the starting y position of snake 1
 *
 * @param gameYPos: Y position of game screen
 * @param unitSize: Size of unit
 * @return Snake 1 starting y position
 */
int SnakeMath::calculateSnake1Y(int gameYPos, int unitSize)
{
    return gameYPos + 10 * unitSize;
}

/**
 * Calculate the starting x position of snake 2
 *
 * @param center:   Y position of center screen
 * @param unitSize: Size of unit
 * @return Snake 2 starting x position
 */
int SnakeMath::calculateSnake2X(int center, int unitSize)
{
    return center + 18 * unitSize;
}

/**
 * Calculate the starting y position of snake 2
 *
 * @param gameYPos: Y position of game screen
 * @param unitSize: Size of unit
 * @return Snake 2 starting y position
 */
int SnakeMath::calculateSnake2Y(int gameYPos, int unitSize)
{
    return gameYPos + 10 * unitSize;
}
