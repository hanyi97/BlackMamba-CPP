#ifndef BLACKMAMBA_GAME_HPP
#define BLACKMAMBA_GAME_HPP

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "StateManager.hpp"
#include "AssetManager.hpp"


namespace Engine
{
    enum AssetID
    {
        BACKGROUND,
        FOOD,
        SNAKE
    };

    struct Context
    {
        std::unique_ptr<Engine::AssetManager> assets;
        std::unique_ptr<Engine::StateManager> states;
        std::unique_ptr<sf::RenderWindow> window;

        Context()
        {
            assets = std::make_unique<Engine::AssetManager>();
            states = std::make_unique<Engine::StateManager>();
            window = std::make_unique<sf::RenderWindow>();
        }
    };

    class Game
    {
    private:
        std::shared_ptr<Context> context;
        const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);
    public:
        Game();
        ~Game();

        void Run();
    };
}


#endif //BLACKMAMBA_GAME_HPP
