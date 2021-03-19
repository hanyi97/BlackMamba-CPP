#ifndef BLACKMAMBA_SETTINGS_HPP
#define BLACKMAMBA_SETTINGS_HPP
#pragma once
namespace Engine
{
    class Settings
    {
    public:
        static const int UNIT_SIZE = 24;
        static const int WINDOW_WIDTH = UNIT_SIZE * 48;
        static const int WINDOW_HEIGHT = UNIT_SIZE * 28;
        static const int GAME_HEIGHT = WINDOW_HEIGHT - 3 * UNIT_SIZE;
        static const int CENTER = WINDOW_WIDTH / 2;
        static const int GAME_YPOS = WINDOW_HEIGHT - GAME_HEIGHT;
    };
}

#endif //BLACKMAMBA_SETTINGS_HPP
