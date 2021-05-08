#ifndef ENTITY_H_
#define ENTITY_H_
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector3.hpp>


struct Animation
{
    bool loop;
    
};


class Entity : public sf::Sprite
{
protected:
    sf::Vector3f velocity;
    sf::Vector3f boundary;
    sf::Vector3f location;

public:
    Entity() = default;
    Entity(const Entity & ) = delete;
    Entity(Entity &&) = delete;
    Entity & operator=(const Entity &) = delete;
    Entity & operator=(Entity &) = delete;

    ~Entity() = default;

    bool iscollided(const Entity &) const;
    friend bool iscollided(const Entity &, const Entity &);

    void update();


    sf::Vector3f getVelocity() const { return velocity; }
    sf::Vector3f getBounds() const { return boundary; }
    sf::Vector3f getLocation() const { return location; }

    void setVelocity(const sf::Vector3f & velocity) { this->velocity = velocity; }
    void setLocation(const sf::Vector3f & location) { this->location = location; }
    void setBounds(const sf::Vector3f & bounds) { this->boundary = bounds; }


};

#endif // ENTITY_H_
