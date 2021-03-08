#include "../../include/GameMath.hpp"
#include <cstdlib>

using namespace Math;


int GameMath::calculateXBound(int center, int unitSize)
{
    return center / unitSize;
}

int GameMath::calculateYBound(int height, int unitSize)
{
    return (height - unitSize) / unitSize;
}

int GameMath::getRandomY(int yPos, int height, int unitSize)
{
    return yPos + rand() % calculateYBound(height, unitSize) * unitSize;
}

int GameMath::getRandomLeftX(int center, int unitSize)
{
    return rand() % calculateXBound(center, unitSize) * unitSize;
}

int GameMath::getRandomRightX(int center, int unitSize)
{
    return (rand() % calculateXBound(center, unitSize) + calculateXBound(center, unitSize)) * unitSize;
}
