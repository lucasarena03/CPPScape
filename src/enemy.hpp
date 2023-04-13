#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "player.hpp"
#include "bullet.hpp"

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    const float SPEED = 25.f;
    const int MAX_HEALTH = 100;
    const float SHOOT_INTERVAL = 5.f; // shoot every 1 second
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape shape;
    int health = MAX_HEALTH;
    std::vector<Bullet> bullets;
    sf::Clock shoot_timer;
    int attacks = 0;
    
public:
    Enemy();
    ~Enemy();
    void update(float dt, Player* player);
    void render(sf::RenderTarget *target);
    void move(sf::Vector2f target_position);
    sf::Vector2f getPosition() { return this->position; }
    bool is_dead();
    void set_dead(bool dead);
    void hit();
    int get_health();
    int get_max_health();
    void set_health(int health);
    std::vector<Bullet> &getBullets();
    void shoot(sf::Vector2f target_pos);
    void special_attack(sf::Vector2f target_pos);
    
};

#endif