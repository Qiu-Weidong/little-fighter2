#include <SFML/Window/Event.hpp>
#include "battle.h"
#include "assetmanager.h"
#include "setting.h"

BattleScene::BattleScene()
{
    auto & bg_texture = AssetManager::getInstance()->getTexture("./res/Background/background1.png");
    auto & fg_texture = AssetManager::getInstance()->getTexture("./res/Background/foreground1.png");
    bg.setTexture(bg_texture);
    fg.setTexture(fg_texture);
    float f = Setting::getInstance()->getWindowHeight() / (float)bg_texture.getSize().y;
    bg.setScale(f, f);
    fg.setScale(f, f);

    auto & bandit_texture = AssetManager::getInstance()->getTexture("./res/charactor/bandit/bandit_0.png");
    bandit.setTexture(bandit_texture);
    bandit.setTextureRect(sf::IntRect(0,0, bandit_texture.getSize().x/ 10, bandit_texture.getSize().y / 7));
    bandit.setScale(2, 2);
    bandit.setPosition(1000, 700);
}

void BattleScene::processEvent(sf::RenderWindow & window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();
    }
}
void BattleScene::update()
{

}
void BattleScene::render(sf::RenderWindow & window) const
{
    window.clear();

    window.draw(bg);

    window.draw(bandit);

    window.draw(fg);

    window.display();
}

