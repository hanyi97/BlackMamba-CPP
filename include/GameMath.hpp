#ifndef BLACKMAMBA_GAMEMATH_HPP
#define BLACKMAMBA_GAMEMATH_HPP

namespace Math
{
    class GameMath
    {
    private:
        static int calculateXBound(int center, int unitSize);
        static int calculateYBound(int height, int unitSize);
    public:
        static int getRandomLeftX(int center, int unitSize);
        static int getRandomRightX(int center, int unitSize);
        static int getRandomY(int yPos, int height, int unitSize);
    };
}


#endif //BLACKMAMBA_GAMEMATH_HPP
