#ifndef BLACKMAMBA_ASSETMANAGER_HPP
#define BLACKMAMBA_ASSETMANAGER_HPP

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
    class AssetManager
    {
    private:
        std::map<int, std::unique_ptr<sf::Texture>> textures;
        std::map<int, std::unique_ptr<sf::Font>> fonts;
    public:
        AssetManager();
        ~AssetManager();

        void AddTexture(int id, const std::string &filePath, bool wantRepeated = false);
        void AddFont(int id, const std::string &filePath);

        const sf::Texture &GetTexture(int id) const;
        const sf::Font &GetFont(int id) const;
    };
}


#endif //BLACKMAMBA_ASSETMANAGER_HPP
