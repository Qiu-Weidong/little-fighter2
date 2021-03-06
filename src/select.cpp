#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "select.h"
#include "assetmanager.h"
#include "setting.h"
#include "director.h"

static sf::String fighter_names[] = {
    "bandit", "bat", "davis", "deep", "dennis", "firen", "firzen", "freeze", "henry",
    "hunter", "jack", "jan", "john", "julian", "justin", "knight", "louis", "mark",
    "monk", "rudolf", "sorcerer", "woody"
};

SelectScene::SelectScene()
{
    sf::String base_path = "./res/face/";
    
    auto pAsset = AssetManager::getInstance();
    auto pSetting = Setting::getInstance();

    for(int i=0;i<fighters.size(); i++)
    {
        fighters[i].setTexture(pAsset->getTexture(base_path+fighter_names[i]+"_f.png"));
        auto rect = fighters[i].getGlobalBounds();
        fighters[i].setOrigin(rect.width / 2.0 , rect.height / 2.0);
        fighters[i].setScale(1.25, 1.25);
        fighters[i].setPosition(
            pSetting->getWindowWidth()*0.1 + (i % 6) * rect.width * 1.5,
            pSetting->getWindowHeight()*0.2 + (i / 6) * rect.height * 1.5
        );
    }
    selected.setScale(3.5, 3.5);
    selected.setPosition(pSetting->getWindowWidth()*0.6, pSetting->getWindowHeight()*0.2);
    selected.setTexture(*fighters[0].getTexture());

    name.setCharacterSize(90);
    name.setFillColor(sf::Color::White);
    name.setFont(pAsset->getFont("res/font/Sudestada.ttf"));
    name.setPosition(pSetting->getWindowWidth() * 0.6, pSetting->getWindowHeight()*0.5);
    name.setString(fighter_names[0]);

    start.setFont(pAsset->getFont("./res/font/menu.ttf"));
    start.setString(L"开始"); 
    start.setCharacterSize(200);

    auto rect = start.getGlobalBounds();
    start.setOrigin(rect.width / 2.0 , rect.height / 2.0);
    start.setPosition(pSetting->getWindowWidth() * 0.5, pSetting->getWindowHeight()*0.8);

    select_fighter = FighterName::Bandit;

}

void SelectScene::processEvent(sf::RenderWindow & window) 
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed) window.close();
        else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
        {
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            for(int i = 0 ; i < fighters.size(); i++)
            {
                auto & fighter = fighters[i];
                auto rect = fighter.getGlobalBounds();
                if (x > rect.left && x < rect.left + rect.width && y > rect.top && y < rect.top + rect.height)
                {
                    selected.setTexture(*fighter.getTexture());
                    name.setString(fighter_names[i]);
                    select_fighter = (FighterName)i;
                }
            }

            auto rect = start.getGlobalBounds();
            if (x > rect.left && x < rect.left + rect.width && y > rect.top && y < rect.top + rect.height)
            {
                Director::getInstance()->switchScene(SceneName::Battle);
            }

        }

        else if(event.type == sf::Event::MouseMoved)
        {
            int x = event.mouseMove.x;
            int y = event.mouseMove.y;
            auto rect = start.getGlobalBounds();
            if (x > rect.left && x < rect.left + rect.width && y > rect.top && y < rect.top + rect.height)
            {
                start.setCharacterSize(250);
            }
            else {
                start.setCharacterSize(200);
            }
            rect = start.getGlobalBounds();
            start.setOrigin(rect.width / 2.0 , rect.height / 2.0);

            for(auto & fighter : fighters)
            {
                rect = fighter.getGlobalBounds();
                if (x > rect.left && x < rect.left + rect.width && y > rect.top && y < rect.top + rect.height)
                {
                    fighter.setScale(1.5, 1.5);
                }
                else fighter.setScale(1.25, 1.25);
            }
        }

    }
}

void SelectScene::render(sf::RenderWindow & window) const 
{
    window.clear(sf::Color::Black);

    for(auto & fighter : fighters) window.draw(fighter);
    window.draw(selected);
    window.draw(name);
    window.draw(start);

    window.display();
}


