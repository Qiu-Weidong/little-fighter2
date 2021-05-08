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

int main()
{
    sf::RenderWindow window(sf::VideoMode(Setting::getInstance()->getWindowWidth(),
                                          Setting::getInstance()->getWindowHeight()),
                            Setting::getInstance()->getWindowTitle(),
                            sf::Style::Titlebar | sf::Style::Close);

    sf::Image icon;
    icon.loadFromFile("./res/face/freeze_f.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(Setting::getInstance()->getFrameLimit());

    auto pDirector = Director::getInstance();

    pDirector->registerScene(SceneName::Menu, MenuScene::create());
    pDirector->registerScene(SceneName::Battle, BattleScene::create());
    pDirector->registerScene(SceneName::Select, SelectScene::create());


    pDirector->playWithScene(SceneName::Menu);

    

    while (window.isOpen())
    {
        pDirector->mainLoop(window);
    }

    delete Director::getInstance();
    delete Setting::getInstance();
    delete AssetManager::getInstance();

    return 0;
}