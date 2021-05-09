#ifndef ANIMATE_H_
#define ANIMATE_H_
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <map>


enum class AnimationID
{
    Idle,
    Walk,
    Run,

    Count 
};

class Animate : public sf::Sprite
{
    struct Animation 
    {
        const sf::Texture * texture;
        std::vector<sf::IntRect> m_frames;
        bool m_loop;
        float speed; // 单位帧/秒
    };

private:
    Animate::Animation * currentAnimation;
    sf::Clock clock;
    static std::map<std::string, Animate::Animation> m_animations;
    void update();
    void switchAnimation();
};



#endif // ANIMATE_H_

