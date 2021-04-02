#include <cstdlib>
#include <iostream>
#include <exception>
#include <windows.h>

#include "../../include/GameMath.hpp"

using namespace Math;

/**
 * Exception when multiplying by 0
 */
struct MultiplyByZero : public std::exception
{
    const char *what() const throw()
    {
        return "MultiplyByZero Exception";
    }
};

/**
 * Exception when dividing by 0
 */
struct DivideByZero : public std::exception
{
    const char *what() const throw()
    {
        return "DivideByZero Exception";
    }
};

/**
 * Calculate bound for random generating of x position
 *
 * @param center:   Center x position
 * @param unitSize: Size of unit
 * @return bound
 */
int GameMath::calculateXBound(int center, int unitSize)
{
    try
    {
        if (unitSize == 0)
        {
            throw DivideByZero();
        }
    }
    catch (DivideByZero &e)
    {
        std::cerr << "DivideByZero exception caught at GameMath::calculateXBound()! unitSize == 0" << std::endl;
        std::cerr << e.what() << std::endl;
        MessageBox(NULL, "DivideByZero error!",
                   "Exception has occurred!", MB_ICONERROR);
        std::terminate();
    }
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
    try
    {
        if (unitSize == 0)
        {
            throw DivideByZero();
        }
    }
    catch (DivideByZero &e)
    {
        std::cerr << "DivideByZero exception caught at GameMath::calculateYBound()! unitSize == 0" << std::endl;
        std::cerr << e.what() << std::endl;
        MessageBox(NULL, "DivideByZero error!",
                   "Exception has occurred!", MB_ICONERROR);
        std::terminate();
    }
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
    try
    {
        if (unitSize == 0) throw MultiplyByZero();
    }
    catch (MultiplyByZero &e)
    {
        std::cerr << "MultiplyByZero exception caught at GameMath::getRandomY()! unitSize == 0" << std::endl;
        std::cerr << e.what() << std::endl;
        MessageBox(NULL, "MultiplyByZero error!",
                   "Exception has occurred!", MB_ICONERROR);
        std::terminate();
    }
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
    try
    {
        if (unitSize == 0) throw MultiplyByZero();
    }
    catch (MultiplyByZero &e)
    {
        std::cerr << "MultiplyByZero exception caught at GameMath::getRandomLeftX()! unitSize == 0" << std::endl;
        std::cerr << e.what() << std::endl;
        MessageBox(NULL, "MultiplyByZero error!",
                   "Exception has occurred!", MB_ICONERROR);
        std::terminate();
    }
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
    try
    {
        if (unitSize == 0) throw MultiplyByZero();
    }
    catch (MultiplyByZero &e)
    {
        std::cerr << "MultiplyByZero exception caught at GameMath::getRandomRightX()! unitSize == 0" << std::endl;
        std::cerr << e.what() << std::endl;
        MessageBox(NULL, "MultiplyByZero error!",
                   "Exception has occurred!", MB_ICONERROR);
        std::terminate();
    }
    return (rand() % calculateXBound(center, unitSize) + calculateXBound(center, unitSize)) * unitSize;
}
