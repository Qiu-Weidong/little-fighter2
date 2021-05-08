#ifndef ASSET_H_
#define ASSET_H_
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <map>
#include <string>
#include <cassert>


class AssetManager
{
private:
    AssetManager() = default;
    
    AssetManager(const AssetManager &) = delete;
    AssetManager(AssetManager &&) = delete;
    AssetManager & operator=(const AssetManager &) = delete;
    AssetManager & operator=(AssetManager &&) = delete;

    static AssetManager * pAssetManager;
    std::map<std::string , sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;
public:
    static AssetManager * getInstance() { return pAssetManager; }
    sf::Texture & getTexture(std::string const filename)
    {
        auto pair = m_textures.find(filename);
        if(pair != m_textures.end()) return pair->second;
        auto & texture = m_textures[filename];
        assert(texture.loadFromFile(filename));
        return texture;
    }

    sf::Font & getFont(std::string const filename)
    {
        auto pair = m_fonts.find(filename);
        if(pair != m_fonts.end()) return pair->second;
        auto & font = m_fonts[filename];
        assert(font.loadFromFile(filename));
        return font;
    }
    
};

#endif // ASSET_H_

