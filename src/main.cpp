#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Image.hpp>
#include <iostream>
#include "director.h"
#include "menu.h"
#include "setting.h"
#include "assetmanager.h"
#include "battle.h"
#include "select.h"


Setting *Setting::pSetting = new Setting();
AssetManager * AssetManager::pAssetManager = new AssetManager();

void join(sf::Image & m1, sf::Image & m2, sf::Image & output)
{
    auto p1 = m1.getPixelsPtr();
    auto p2 = m2.getPixelsPtr();
    int x1 = m1.getSize().x;
    int y1 = m1.getSize().y;
    int x2 = m2.getSize().x;
    int y2 = m2.getSize().y;
    int len1 = x1 * y1 * 4;
    int len2 = x2 * y2 * 4;
    sf::Uint8 * p3 = new sf::Uint8[len1 + len2];
    for(int i=0;i<len1;i++) p3[i] = p1[i];
    for(int i=len1;i<len1+len2;i++) p3[i] = p2[i-len1];
    output.create(m1.getSize().x, (m1.getSize().y+m2.getSize().y), p3);
}
void join2(sf::Image & m1, sf::Image & m2, sf::Image & output)
{
    int x1 = m1.getSize().x;
    int y = m1.getSize().y;
    assert(y == m2.getSize().y);
    int x2 = m2.getSize().x;
    auto p1 = m1.getPixelsPtr();
    auto p2 = m2.getPixelsPtr();
    auto p3 = new sf::Uint8[x1*y*4 + x2*y*4];
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x1*4;j++)
            p3[i*(x1+x2)*4+j] = p1[i*x1*4+j];
        for(int j=x1*4; j<x1*4+x2*4;j++)
            p3[i*(x1+x2)*4+j] = p2[i*x2*4+j-x1*4];
    }
    output.create(x1+x2, y, p3);

}


int main()
{
    sf::RenderWindow window(sf::VideoMode(Setting::getInstance()->getWindowWidth(),
                                          Setting::getInstance()->getWindowHeight()),
                            Setting::getInstance()->getWindowTitle(),
                            sf::Style::Titlebar | sf::Style::Close);

    // sf::Image icon;
    // icon.loadFromFile("./res/face/freeze_f.png");
    // window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // window.setFramerateLimit(Setting::getInstance()->getFrameLimit());

    // auto pDirector = Director::getInstance();

    // pDirector->registerScene(SceneName::Menu, MenuScene::create());
    // pDirector->registerScene(SceneName::Battle, BattleScene::create());
    // pDirector->registerScene(SceneName::Select, SelectScene::create());


    // pDirector->playWithScene(SceneName::Menu);
    sf::Image b1;
    sf::Image b2;
    sf::Image b3;
    b1.loadFromFile("./res/charactor/bandit/bandit_b.png");
    b2.loadFromFile("./res/charactor/bandit/bandit_b_mirror.png");
    join2(b1, b2, b3);
    b3.saveToFile("./res/charactor/bandit/bandit_b.png");
    sf::Texture t;
    t.loadFromImage(b3);
    sf::Sprite s(t);
    

    while (window.isOpen())
    {
        // pDirector->mainLoop(window);
        window.clear();
        window.draw(s);
        window.display();
    }

    delete Director::getInstance();
    delete Setting::getInstance();
    delete AssetManager::getInstance();

    return 0;
}