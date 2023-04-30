/**
 * @file bullet.cpp
 * @brief Bullet class implementation file
 * @author Lucas Arena
 * @version 0.1
 */

#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    // variables
    float SPEED = 500.f;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape shape;
    bool dead = false;

public:
    // functions
    Bullet(sf::Vector2f pos, sf::Vector2f target_pos);
    void update(float dt);
    void render(sf::RenderTarget *target);
    sf::FloatRect getGlobalBounds();
    bool is_dead();
    void set_dead(bool dead);
};

#endif
