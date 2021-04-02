#ifndef BLACKMAMBA_SOUND_HPP
#define BLACKMAMBA_SOUND_HPP

namespace Engine
{
    class Sound
    {
    protected:
        bool checker = true;
    public:
        void setPlay(bool);
        void playBGM();
        void stopBGM();
        void playBadFood();
        void playGoodFood();
        void playGameOver();
    };
}

#endif
