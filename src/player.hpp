#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>
#include "bullet.hpp"

class Player
{
private:
    const long SHOOT_INTERVAL = 1000; // shoot every 1 second
    const float SPEED = 100.f;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape shape;
    sf::Vector2f target_position;
    std::vector<Bullet> bullets;
    sf::Clock shoot_timer;

public:
    Player();
    ~Player();
    void update(float dt);
    void render(sf::RenderTarget *target);
    void move(sf::Vector2f target_position);
    sf::Vector2f getPosition() { return this->position; }
    void shoot(sf::Vector2f target_position);
    std::vector<Bullet> &getBullets();
};

#endif