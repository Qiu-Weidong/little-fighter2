#include <cassert>
#include <iostream>
#include "director.h"

Director *Director::pDirector = new Director();

Director *Director::getInstance()
{
    return pDirector;
}
Director::Director()
{
    this->currentScene = nullptr;
    this->nextScene = nullptr;
    this->registeredScenes.fill(nullptr);
}
Director::~Director()
{
    assert(pDirector == this);
    pDirector = nullptr;
    for (auto scene : registeredScenes)
    {
        if(scene != nullptr) delete scene;
    }
}

void Director::playWithScene(SceneName scene)
{
    assert(scene < SceneName::Count);
    auto p = registeredScenes.at((std::size_t)scene);
    assert(p != nullptr);
    currentScene = p;
    nextScene = nullptr;
}
void Director::switchScene(SceneName scene)
{
    if (nextScene != nullptr)
        return;
    assert(scene < SceneName::Count);
    auto pScene = registeredScenes[(std::size_t)scene];
    assert(pScene != nullptr);
    nextScene = pScene;
}
void Director::pushScene(SceneName scene)
{
    // 如果nextScene不为空，那么我们要push的是nextScene
    if (nextScene != nullptr)
        sceneStack.push(nextScene), nextScene = nullptr;
    else
        sceneStack.push(currentScene);
    // currentScene = scene;
    playWithScene(scene);
}
Scene *Director::popScene()
{
    assert(!sceneStack.empty());
    nextScene = sceneStack.top();
    sceneStack.pop();
    return nextScene;
}
void Director::mainLoop(sf::RenderWindow &window)
{
    if (nextScene != nullptr)
    {
        currentScene = nextScene;
        nextScene = nullptr;
    }

    assert(currentScene != nullptr);
    // 处理事件
    window >> *currentScene; // 或者 currentScene->processEvent(window);

    // 场景更新
    currentScene->update();
    
    // 渲染 render
    window << *currentScene; // 或者 currentScene->render(window);
}

Scene *Director::getCurrentScene() const
{
    return currentScene;
}

void Director::registerScene(SceneName name, Scene *scene)
{
    // 这里使用数组方式直接覆盖掉原来的数据
    assert(name < SceneName::Count);
    auto pScene = registeredScenes[(std::size_t)name];
    if(pScene != nullptr) delete pScene;
    registeredScenes[(std::size_t)name] = scene;
}
