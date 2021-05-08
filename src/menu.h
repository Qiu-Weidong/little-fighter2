#ifndef MENUSCENE_H_
#define MENUSCENE_H_
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <array>
#include "scene.h"

class MenuScene : public Scene
{
private:
    MenuScene();
    MenuScene(const MenuScene &) = delete;
    MenuScene(MenuScene &&) = delete;
    MenuScene & operator=(const MenuScene &) = delete;
    MenuScene & operator=(MenuScene &&) = delete;


    sf::Text title;
    
    std::array<sf::Text, 4> menuItems;
    sf::Text * hovered;
public:

    static MenuScene * create() { return new MenuScene(); }

    virtual void processEvent(sf::RenderWindow &) override;
    virtual void update() override;
    virtual void render(sf::RenderWindow &) const override;
};

#endif // MENUSCENE_H_