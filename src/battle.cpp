#include <SFML/Window/Event.hpp>
#include <iostream>
#include <vector>
#include "battle.h"
#include "assetmanager.h"
#include "setting.h"



std::vector<sf::IntRect> rects ;
BattleScene::BattleScene()
{
    auto & bg_texture = AssetManager::getInstance()->getTexture("./resources/Background/background1.png");
    auto & fg_texture = AssetManager::getInstance()->getTexture("./resources/Background/foreground1.png");
    bg.setTexture(bg_texture);
    fg.setTexture(fg_texture);
    float f = Setting::getInstance()->getWindowHeight() / (float)bg_texture.getSize().y;
    bg.setScale(f, f);
    fg.setScale(f, f);
    auto & bandit_texture = AssetManager::getInstance()->getTexture("./resources/charactor/bandit.png");
    bandit.setTexture(bandit_texture);
    bandit.setTextureRect(sf::IntRect(0,0, bandit_texture.getSize().x/ 20, bandit_texture.getSize().y / 14));
    bandit.setScale(2, 2);
    bandit.setPosition(1000, 800);

    // 80 * 80
    for(int i=0;i<4;i++)
    {
        rects.push_back(sf::IntRect(480+80*i, 240, 80, 80));
    }
    // rects.push_back(sf::IntRect(80, 160, 80, 80));
    // rects.push_back(sf::IntRect(0, 0, 80, 80));
    // rects.push_back(sf::IntRect(320+80*2,0, 80, 80));
    // rects.push_back(sf::IntRect(320+80*1, 0, 80 , 80));
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
    static int delta = 1;
    auto & bandit_texture = *bandit.getTexture();
    int x = bandit_texture.getSize().x / 20;
    int y = bandit_texture.getSize().y / 14;
    bandit.setTextureRect(rects[idx]);
    // idx += delta;
    // if(idx >= 4) delta = -1, idx--;
    // else if(idx < 0) delta = 1, idx++;
    idx++;
    if(idx >= rects.size()) idx = 0;
    // for(int i=0;i<4;i++)
    // {
    //     rects.push_back(sf::IntRect(320+80*i, 0, 80, 80));
    // }
}
void BattleScene::render(sf::RenderWindow & window) const
{
    window.clear();

    window.draw(bg);

    window.draw(bandit);

    window.draw(fg);

    window.display();
}

