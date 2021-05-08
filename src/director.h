#ifndef DIRECTOR_H_
#define DIRECTOR_H_
#include <SFML/Graphics.hpp>
#include <stack>
#include <array>
#include "scene.h"

class Director
{
private:
    static Director *pDirector;
    Scene *currentScene;
    Scene *nextScene;
    std::stack<Scene *> sceneStack;
    std::array<Scene *, (std::size_t)SceneName::Count> registeredScenes;

    Director();

public:
    static Director *getInstance();

    ~Director();
    Director(const Director &) = delete;
    Director(Director &&) = delete;
    Director &operator=(const Director &) = delete;
    Director &operator=(Director &&) = delete;

    void playWithScene(SceneName scene);
    void switchScene(SceneName scene);
    void pushScene(SceneName scene);
    Scene *popScene();
    void mainLoop(sf::RenderWindow &window);

    Scene *getCurrentScene() const;
    void registerScene(SceneName name, Scene *scene);
};

#endif // DIRECTOR_H_
