#ifndef SELECT_H_
#define SELECT_H_
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <array>
#include "scene.h"

enum class FighterName
{
    Bandit,
    Bat,
    Davis,
    Deep,
    Dennis,
    Firen,
    Firzen,
    Freeze,
    Henry,
    Hunter,
    Jack,
    Jan,
    John,
    Julian,
    Justin,
    Knight,
    Louis,
    Mark,
    Monk,
    Rudolf,
    Sorcerer,
    Woody,

    Count
};

class SelectScene : public Scene
{
private:
    SelectScene();

    SelectScene(const SelectScene &) = delete;
    SelectScene(SelectScene &&) = delete;
    SelectScene &operator=(const SelectScene &) = delete;
    SelectScene &operator=(SelectScene &&) = delete;

    std::array<sf::Sprite, (std::size_t)FighterName::Count> fighters;
    sf::Sprite selected;
    sf::Text name;
    sf::Text start;
public:
    static SelectScene *create() { return new SelectScene(); }

    virtual void processEvent(sf::RenderWindow &) override;
    virtual void update() override;
    virtual void render(sf::RenderWindow &) const override;
};

#endif // SELECT_H_
