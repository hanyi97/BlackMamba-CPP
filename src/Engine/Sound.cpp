//
// Created by mynam on 28-Mar-21.
//

#include "../../include/Sound.hpp"

#include "../../include/Sound.hpp"

#include <iostream>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>



using namespace std;


void Sound::check(bool a) {
    if (a == true) {
        checker = true;
    } else {
        checker = false;
    }
}

void Sound::playBGM() {
    if (checker == false) {
        mciSendString("stop sound", NULL, 0, NULL);
    } else {
        mciSendString("open \"..\\assets\\sounds\\bgm.wav\" type mpegvideo alias bgm", NULL, 0, NULL);
        mciSendString("play bgm repeat", NULL, 0, NULL);

    }

}

void Sound::playGoodFood() {
    char goodFood[] = {"..\\assets\\sounds\\goodFood.wav"};
    string goodFood_str;
    fstream fp;
    fp.open(goodFood,ios::in);
    goodFood_str = goodFood;
    PlaySound(goodFood_str.c_str(), NULL, SND_FILENAME|SND_ASYNC);
    fp.close();

    //PlaySound("..\\assets\\sounds\\goodFood.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);



}

void Sound::playBadFood() {
    char goodFood[] = {"..\\assets\\sounds\\badFood.wav"};
    string goodFood_str;
    fstream fp;
    fp.open(goodFood,ios::in);
    goodFood_str = goodFood;
    PlaySound(goodFood_str.c_str(), NULL, SND_FILENAME|SND_ASYNC);
    fp.close();

}

void Sound::playGameOver() {
    char go[] = {"..\\assets\\sounds\\gameover.wav"};
    string go_str;
    fstream fp;
    fp.open(go,ios::in);
    go_str = go;
    PlaySound(go_str.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    fp.close();
}

void Sound::playWin() {
    char win[] = {"..\\assets\\sounds\\winner.wav"};
    string win_str;
    fstream fp;
    fp.open(win,ios::in);
    win_str = win;
    PlaySound(win_str.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    fp.close();
}