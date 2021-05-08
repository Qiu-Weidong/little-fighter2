#ifndef SCENE_H_
#define SCENE_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

// 每完成一个场景，在这里登记一下
enum class SceneName
{
    Menu,
    Select,
    Battle,

    Count // 放在最后，用来统计场景个数
};

class Scene
{
protected:
    Scene() = default;

    Scene(const Scene &) = delete;
    Scene(Scene &&) = delete;
    Scene &operator=(const Scene &) = delete;
    Scene &operator=(Scene &&) = delete;

public:
    virtual ~Scene() = default;

    friend sf::RenderWindow &operator<<(sf::RenderWindow & window, const Scene & scene)
    {
        scene.render(window);
        return window;
    }
    friend sf::RenderWindow &operator>>(sf::RenderWindow & window, Scene & scene)
    {
        scene.processEvent(window);
        return window;
    }

    virtual void processEvent(sf::RenderWindow &) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow &) const = 0;
};

#endif // SCENE_H_
