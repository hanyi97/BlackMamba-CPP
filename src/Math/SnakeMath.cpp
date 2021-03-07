#include "../../include/SnakeMath.hpp"
using namespace Math;

int SnakeMath::calculateSnake1X(int unitSize)
{
    return 5 * unitSize;
}

int SnakeMath::calculateSnake1Y(int gameYPos, int unitSize)
{
    return gameYPos + 10 * unitSize;
}

int SnakeMath::calculateSnake2X(int center, int unitSize)
{
    return center + 18 * unitSize;
}

int SnakeMath::calculateSnake2Y(int gameYPos, int unitSize)
{
    return gameYPos + 10 * unitSize;
}
