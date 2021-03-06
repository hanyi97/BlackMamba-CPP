#ifndef BLACKMAMBA_GAMEPANEL_HPP
#define BLACKMAMBA_GAMEPANEL_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Food.hpp"

namespace Engine
{
    class GamePanel : public State
    {
    private:
        std::shared_ptr<Context> context;
        sf::Time elapsedTime;
        sf::Sprite background;
        sf::RectangleShape panel;
        Food food1;
        Food food2;
    public:
        GamePanel(std::shared_ptr<Context> &context);
        ~GamePanel();

        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
        void Pause() override;
        void Start() override;
        void drawGrid();
    };
}

#endif //BLACKMAMBA_GAMEPANEL_HPP
