#ifndef BLACKMAMBA_SNAKEMATH_HPP
#define BLACKMAMBA_SNAKEMATH_HPP

namespace Math
{
    class SnakeMath
    {
    public:
        static int calculateSnake1X(int unitSize);
        static int calculateSnake1Y(int gameYPos, int unitSize);
        static int calculateSnake2X(int center, int unitSize);
        static int calculateSnake2Y(int gameYPos, int unitSize);
    };
}


#endif //BLACKMAMBA_SNAKEMATH_HPP
