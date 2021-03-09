#include "../../include/GameMath.hpp"
#include <cstdlib>

using namespace Math;

/**
 * Calculate bound for random generating of x position
 *
 * @param center:   Center x position
 * @param unitSize: Size of unit
 * @return bound
 */
int GameMath::calculateXBound(int center, int unitSize)
{
    return center / unitSize;
}

/**
 * Calculate bound for random generating of y position
 *
 * @param height:   Height of window
 * @param unitSize: Size of unit
 * @return bound
 */
int GameMath::calculateYBound(int height, int unitSize)
{
    return (height - unitSize) / unitSize;
}

/**
 * Generate a random y position for game screen
 *
 * @param yPos:     y position
 * @param height:   Height of game window
 * @param unitSize: Size of unit
 * @return randomly generated y position
 */
int GameMath::getRandomY(int yPos, int height, int unitSize)
{
    return yPos + rand() % calculateYBound(height, unitSize) * unitSize;
}

/**
 * Generate a random x position for left screen
 *
 * @param center:   Center screen position
 * @param unitSize: Size of unit
 * @return randomly selected x position for left screen
 */
int GameMath::getRandomLeftX(int center, int unitSize)
{
    return rand() % calculateXBound(center, unitSize) * unitSize;
}

/**
 * Generate a random x position for right screen
 *
 * @param center:   Center screen position
 * @param unitSize: Size of unit
 * @return randomly selected x position for right screen
 */
int GameMath::getRandomRightX(int center, int unitSize)
{
    return (rand() % calculateXBound(center, unitSize) + calculateXBound(center, unitSize)) * unitSize;
}
