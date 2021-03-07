#include "../../include/AssetManager.hpp"

using namespace Engine;

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::AddTexture(int id, const std::string &filePath, bool wantRepeated)
{
    auto texture = std::make_unique<sf::Texture>();

    if(texture->loadFromFile(filePath))
    {
        texture->setRepeated(wantRepeated);
        textures[id] = std::move(texture);
    }
}

void AssetManager::AddFont(int id, const std::string &filePath)
{
    auto font = std::make_unique<sf::Font>();

    if(font->loadFromFile(filePath))
    {
        fonts[id] = std::move(font);
    }
}

const sf::Texture &AssetManager::GetTexture(int id) const
{
    return *(textures.at(id).get());
}

const sf::Font &AssetManager::GetFont(int id) const
{
    return *(fonts.at(id).get());
}