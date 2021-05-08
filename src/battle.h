#ifndef BATTLE_H_
#define BATTLE_H_
#include <SFML/Graphics/Sprite.hpp>
#include "scene.h"


class BattleScene : public Scene
{
private:
    BattleScene();
    BattleScene(const BattleScene &) = delete;
    BattleScene(BattleScene &&) = delete;
    BattleScene & operator=(const BattleScene &) = delete;
    BattleScene & operator=(BattleScene &&) = delete;

    sf::Sprite bg, fg;
    sf::Sprite bandit; 

public :
    static BattleScene * create() { return new BattleScene(); }
    virtual void processEvent(sf::RenderWindow &) override;
    virtual void update() override;
    virtual void render(sf::RenderWindow &) const override;
};


#endif // BATTLE_H_

