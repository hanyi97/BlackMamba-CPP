#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#include "../../include/Sound.hpp"

using namespace std;
using namespace Engine;

void Sound::setPlay(bool flag)
{
    this->checker = flag;
}

/**
 * Plays background music
 */
void Sound::playBGM()
{
    if (checker == true)
    {
        mciSendString(R"(open "..\assets\sounds\bgm.wav" type mpegvideo alias bgm)", NULL, 0, NULL);
        mciSendString("play bgm repeat", NULL, 0, NULL);
    }
    else
    {
        mciSendString("stop bgm", NULL, 0, NULL);
    }
}

/**
 * Stops background music
 */
void Sound::stopBGM()
{
    if (checker == false)
    {
        mciSendString("stop bgm", NULL, 0, NULL);
        mciSendString("close bgm", NULL, 0, NULL);
    }
}

/**
 * Plays sound when snake ate a food
 */
void Sound::playGoodFood()
{
    char goodFood[] = {"..\\assets\\sounds\\goodFood.wav"};
    string goodFood_str;
    fstream fp;
    fp.open(goodFood, ios::in);
    goodFood_str = goodFood;
    PlaySound(goodFood_str.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    fp.close();
}

/**
 * Plays sound when snake ate a poison
 */
void Sound::playBadFood()
{
    char goodFood[] = {"..\\assets\\sounds\\badFood.wav"};
    string goodFood_str;
    fstream fp;
    fp.open(goodFood, ios::in);
    goodFood_str = goodFood;
    PlaySound(goodFood_str.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    fp.close();
}

/**
 * Plays game over sound
 */
void Sound::playGameOver()
{
    char go[] = {"..\\assets\\sounds\\gameover.wav"};
    string go_str;
    fstream fp;
    fp.open(go, ios::in);
    go_str = go;
    PlaySound(go_str.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    fp.close();
}