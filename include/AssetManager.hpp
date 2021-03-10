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

        void addTexture(int id, const std::string &filePath, bool wantRepeated = false);
        void addFont(int id, const std::string &filePath);

        const sf::Texture &getTexture(int id) const;
        const sf::Font &getFont(int id) const;
    };
}


#endif //BLACKMAMBA_ASSETMANAGER_HPP
