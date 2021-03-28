//
// Created by mynam on 28-Mar-21.
//

#ifndef BLACKMAMBA_SOUND_HPP
#define BLACKMAMBA_SOUND_HPP

class Sound {
protected:
    bool checker = true;
public:
    void check(bool);
    void playBGM();
    void playBadFood();
    void playGoodFood();
    void playGameOver();
    void playWin();

};


#endif //BLACKMAMBA_SOUND_HPP
