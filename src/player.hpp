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
#include "healthbars.hpp"

class Enemy;

class Player
{
private:
    const float WIDTH = 32.0f;
    const float HEIGHT = 32.0f;
    const long SHOOT_INTERVAL = 1000; // shoot every 1 second
    const float SPEED = 100.f;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape shape;
    sf::Vector2f target_position;
    std::vector<Bullet> bullets;
    sf::Clock shoot_timer;
    const int MAX_HEALTH = 100;
    int health = MAX_HEALTH;
    HealthBar healthbar = HealthBar(sf::Vector2f(0, 0));

public:
    Player();
    ~Player();
    void update(float dt, Enemy *enemy);
    void render(sf::RenderTarget *target);
    void move(sf::Vector2f target_position);
    sf::Vector2f getPosition() { return this->position; }
    void shoot(sf::Vector2f target_position);
    std::vector<Bullet> &getBullets();
    void hit();
    int get_health();
    int get_max_health();
    void set_health(int health);
    bool is_dead();
    void set_dead(bool dead);
};

#endif