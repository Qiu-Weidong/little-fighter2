#include <SFML/Window/Event.hpp>
#include <iostream>
#include "menu.h"
#include "assetmanager.h"
#include "setting.h"
#include "director.h"

MenuScene::MenuScene()
{
    auto pSetting = Setting::getInstance();
    auto pAsset = AssetManager::getInstance();

    title.setFont(pAsset->getFont("./res/font/title.ttf"));
    title.setCharacterSize(250);
    title.setFillColor(sf::Color::White);
    title.setString(pSetting->getWindowTitle());
    title.setPosition(pSetting->getWindowWidth() / 2.0, pSetting->getWindowHeight() * 0.3);
    auto rect = title.getLocalBounds();
    title.setOrigin(rect.width / 2.0, rect.height / 2.0);

    sf::Font &item_font = pAsset->getFont("./res/font/menu.ttf");
    sf::String content[4] = {
        L"开始游戏", L"游戏设置", L"游戏帮助", L"离开"};
        
    for (int i = 0; i < menuItems.size(); i++)
    {
        menuItems[i].setFont(item_font);
        menuItems[i].setFillColor(sf::Color::Red);
        menuItems[i].setString(content[i]);
        menuItems[i].setCharacterSize(90);
        auto rect = menuItems[i].getLocalBounds();
        menuItems[i].setOrigin(rect.width / 2.0, rect.height / 2.0);
        menuItems[i].setPosition(pSetting->getWindowWidth() / 2.0, pSetting->getWindowHeight() * 0.5 + i * rect.height * 1.5);
    }

    hovered = nullptr;
}


void MenuScene::processEvent(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseMoved)
        {
            int x = event.mouseMove.x;
            int y = event.mouseMove.y;
            hovered = nullptr;
            for(auto & item : menuItems)
            {
                auto rect = item.getGlobalBounds();
                if (x > rect.left && x < rect.left + rect.width && y > rect.top && y < rect.top + rect.height)
                    hovered = &item;
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
        {
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            auto rect = menuItems[0].getGlobalBounds();
            if (x > rect.left && x < rect.left + rect.width && y > rect.top && y < rect.top + rect.height)
            {
                Director::getInstance()->switchScene(SceneName::Select);
                return;
            }

            rect = menuItems[3].getGlobalBounds();
            if (x > rect.left && x < rect.left + rect.width && y > rect.top && y < rect.top + rect.height)
            {
                window.close();
                return;
            }
        }
    }
}
void MenuScene::update()
{
    auto pSetting = Setting::getInstance();
    for (auto &item : menuItems)
    {
        item.setCharacterSize(90);
        auto rect = item.getGlobalBounds();
        item.setOrigin(rect.width / 2.0, rect.height / 2.0);
    }
    if (hovered != nullptr)
    {
        auto &item = *hovered;
        item.setCharacterSize(100);
        auto rect = item.getLocalBounds();
        item.setOrigin(rect.width / 2.0, rect.height / 2.0);
    }

}
void MenuScene::render(sf::RenderWindow &window) const
{
    window.clear();

    window.draw(title);
    for (auto &item : menuItems)
        window.draw(item);

    window.display();
}
