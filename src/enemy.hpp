#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>


class Enemy
{
private:
    const float SPEED = 75.f;

    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape shape;

public:
    Enemy();
    ~Enemy();
    void update(float dt, Player*player);
    void render(sf::RenderTarget *target);
    
    void move(sf::Vector2f target_position);
    sf::Vector2f getPosition() { return this->position; }
};

#endif
