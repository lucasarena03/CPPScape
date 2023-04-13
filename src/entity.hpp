
#ifndef CPPSCAPE_ENTITY_HPP
#define CPPSCAPE_ENTITY_HPP


#include <SFML/Graphics.hpp>


class Entity {
protected:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape shape;
    bool dead = false;

public:
    Entity();
    virtual ~Entity();

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget *target) = 0;

    sf::Vector2f getPosition() { return this->position; }
    bool is_dead();
    void set_dead(bool dead);
};

#endif 