/**
 * @file enemy.hpp
 * @brief Enemy class for the game
 * @author Lucas Arena
 * @version 0.1
 */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "player.hpp"
#include "bullet.hpp"
#include "weapon.hpp"

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    // constants
    const float SPEED = 25.f;
    const int MAX_HEALTH = 100;
    const float SHOOT_INTERVAL = 5.f; // shoot every 1 second
    // variables
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Texture texture;
    sf::Sprite sprite;
    int health = MAX_HEALTH;
    sf::Clock shoot_timer;
    int attacks = 0;
    Weapon weapon;

public:
    Enemy();
    ~Enemy();
    // functions
    void update(float dt, Player *player);
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