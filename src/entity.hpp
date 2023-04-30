/**
 * @file entity.cpp
 * @brief  Entity class implementation file
 * @author Lucas Arena
 * @version 0.1
 */

#ifndef CPPSCAPE_ENTITY_HPP
#define CPPSCAPE_ENTITY_HPP

#include <SFML/Graphics.hpp>

/**
 * @class Entity
 * @brief Base class for all entities in the game
 */

class Entity
{
protected:
    // variables
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape shape;
    bool dead = false;

public:
    // functions
    Entity();
    virtual ~Entity();
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget *target) = 0;
    sf::Vector2f getPosition() { return this->position; }
    bool is_dead();
    void set_dead(bool dead);
};

#endif