/**
 * @file enemy.cpp
 * @brief Enemy class implementation file
 * @author Lucas Arena
 * @version 0.1
 */

#include "enemy.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>

#include "globals.hpp"
/**
 * @brief Enemy constructor
 */
Enemy::Enemy()
{
    // Enemy position
    this->position = sf::Vector2f(0.f, 0.f);
    // Enemy sprite
    if (!this->texture.loadFromFile("assets\\enemy.png"))
    {
        std::cout << "Error loading player texture" << std::endl;
    }
    this->sprite.setTexture(this->texture);
}

Enemy::~Enemy()
{
}

/**
 * @brief Update the enemy position
 */
void Enemy::update(float dt, Player *player)
{
    // Enemy movement
    sf::Vector2f player_pos = player->getPosition();
    sf::Vector2f direction = player_pos - this->position;
    float distance = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (distance)
    {
        direction = direction / distance;
    }
    this->velocity = direction * SPEED;
    this->position += this->velocity * dt;
    this->sprite.setPosition(this->position);

    // Enemy shooting
    for (auto &bullet : player->getBullets())
    {
        if (bullet.is_dead())
        {
            continue;
        }
        if (bullet.getGlobalBounds().intersects(this->sprite.getGlobalBounds()))
        {
            bullet.set_dead(true);
            this->hit();
        }
    }

    // Enemy attacks
    if (this->shoot_timer.getElapsedTime().asSeconds() >= this->SHOOT_INTERVAL)
    {
        this->shoot_timer.restart();
        attacks = (attacks + 1) % 3;
        if (attacks == 0)
        {
            this->special_attack(player_pos);
        }
        else
        {
            this->shoot(player_pos);
        }
    }

    weapon.update(dt);
    // Enemy death
    if (this->is_dead())
    {
        this->sprite.setPosition(-100, -100);
        this->weapon.getBullets().clear();
    }
}

void Enemy::render(sf::RenderTarget *target)
{
    // Draw the enemy
    target->draw(sprite);
    weapon.render(target);

    // Change the enemy sprite if it's health is below half
    if (this->health <= this->MAX_HEALTH / 2)
    {
        if (!this->texture.loadFromFile("assets\\enemy2.png"))
        {
            std::cout << "Error loading player texture" << std::endl;
        }
        this->sprite.setTexture(this->texture);
    }

    // Draw the enemy health bar
    if (this->is_dead())
    {
        this->sprite.setPosition(-100, -100);
        this->weapon.getBullets().clear();
    }
}

/**
 * @brief Enemy movement
 */
void Enemy::move(sf::Vector2f target_position)
{
    // Enemy movement
    sf::Vector2f direction = target_position - this->position;
    float distance = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (distance)
    {
        direction = direction / distance;
    }
    this->velocity = direction * SPEED;
    this->position += this->velocity;
    this->sprite.setPosition(this->position);
}

/**
 * @brief Enemy death
 */
bool Enemy::is_dead()
{
    return this->health <= 0;
}

/**
 * @brief Enemy death
 */
void Enemy::set_dead(bool dead)
{
    if (dead)
    {
        this->health = 0;
    }
}

/**
 * @brief Enemy health when hit
 */
void Enemy::hit()
{
    this->health -= 10;
}

/**
 * @brief Enemy health
 */
int Enemy::get_health()
{
    return this->health;
}

/**
 * @brief Enemy max health
 */
int Enemy::get_max_health()
{
    return this->MAX_HEALTH;
}

/**
 * @brief Set enemy health
 */
void Enemy::set_health(int health)
{
    this->health = health;
}

/**
 * @brief Enemy shooting
 */
void Enemy::shoot(sf::Vector2f target_pos)
{
    sf::Vector2f center = this->position + sf::Vector2f(128.0f, 128.0f);

    this->weapon.getBullets().push_back(Bullet(center, target_pos));
}

/**
 * @brief Enemy special attack shoot three bullets at once
 */
void Enemy::special_attack(sf::Vector2f target_pos)
{
    for (int i = 0; i < 5; i++)
    {
        this->weapon.getBullets().push_back(Bullet(this->position, target_pos));
        target_pos += sf::Vector2f(rand() % 70 - 35, rand() % 70 - 35);
    }
}

/**
 * @brief Get enemy bullets
 */
std::vector<Bullet> &Enemy::getBullets()
{
    return this->weapon.getBullets();
}
