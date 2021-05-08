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

    auto & bandit_texture = AssetManager::getInstance()->getTexture("./res/charactor/bandit.png");
    bandit.setTexture(bandit_texture);
    bandit.setTextureRect(sf::IntRect(0,0, bandit_texture.getSize().x/ 20, bandit_texture.getSize().y / 14));
    bandit.setScale(2, 2);
    bandit.setPosition(1000, 800);
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
    static int idx = 0;
    auto & bandit_texture = *bandit.getTexture();
    int x = bandit_texture.getSize().x / 20;
    int y = bandit_texture.getSize().y / 14;
    bandit.setTextureRect(sf::IntRect(x*(idx % 20), y*(idx / 20), x, y));
    idx++;
    if(idx >= 280) idx = 0;
}
void BattleScene::render(sf::RenderWindow & window) const
{
    window.clear();

    window.draw(bg);

    window.draw(bandit);

    window.draw(fg);

    window.display();
}

