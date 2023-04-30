/**
 * @file player.cpp
 * @brief Player class implementation file
 * @author Lucas Arena
 * @version 0.1
 */

#include "player.hpp"

#include <iostream>
#include <cmath>
#include <vector>

#include "globals.hpp"
#include "enemy.hpp"

/**
 * @brief Player constructor
 */
Player::Player()
{
    // Player position
    this->position = sf::Vector2f(W_WIDTH - 56, W_HEIGHT - 56);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->target_position = this->position;
    // Player texture
    if (!this->texture.loadFromFile("assets\\player.png"))
    {
        std::cout << "Error loading player texture" << std::endl;
    }
    this->sprite.setTexture(this->texture);
}
/**
 * @brief Player destructor
 */
Player::~Player()
{
}

/**
 * @brief Update the player
 */
void Player::update(float dt, Enemy *enemy)
{
    // RuneScape movement
    sf::Vector2f direction = target_position - position;
    float magnitude = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (magnitude)
    {
        direction = direction / magnitude;
    }
    this->velocity = direction * SPEED;
    this->position += this->velocity * dt;
    this->sprite.setPosition(this->position);

    // Player shooting
    for (int i = 0; i < this->weapon.getBullets().size(); i++)
    {
        Bullet &bullet = getBullets()[i];
        bullet.update(dt);

        if (bullet.is_dead())
        {
            getBullets().erase(getBullets().begin() + i--);
        }
    }

    // Player collision with enemy bullets
    for (auto &bullet : enemy->getBullets())
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

    // Player health
    if (this->health <= 0)
    {
        this->set_dead(true);
    }

    // Healthbar Position
    healthbar.setPosition(sf::Vector2f(this->position.x + WIDTH / 2 - healthbar.WIDTH / 2, this->position.y - 20));
    healthbar.update(this->health / (float)this->MAX_HEALTH);
}

/**
 * @brief Render the player
 */
void Player::render(sf::RenderTarget *target)
{
    // Render player sprite
    target->draw(sprite);
    for (auto &bullet : weapon.getBullets())
    {
        bullet.render(target);
    }

    // Player death
    if (this->is_dead())
    {
        this->sprite.setPosition(-100, -100);
        this->weapon.getBullets().clear();
    }

    // Render healthbar
    healthbar.render(target);
}

/**
 * @brief Move the player
 */
void Player::move(sf::Vector2f target_positon)
{
    this->target_position = target_positon;
}

/**
 * @brief Shoot a bullet
 */
void Player::shoot(sf::Vector2f target_position)
{
    // Shoot interval
    if (this->shoot_timer.getElapsedTime().asMilliseconds() < SHOOT_INTERVAL)
    {
        return;
    }
    Bullet bullet(this->position + sf::Vector2f(11, 11), target_position);
    this->weapon.getBullets().push_back(bullet);
    this->shoot_timer.restart();
}

/**
 * @brief Get the player bullets
 */
std::vector<Bullet> &Player::getBullets()
{
    return this->weapon.getBullets();
}

/**
 * @brief Player death
 */
bool Player::is_dead()
{
    return this->health <= 0;
}

/**
 * @brief Set player death
 */
void Player::set_dead(bool dead)
{
    if (dead)
    {
        this->health = 0;
    }
}

/**
 * @brief Player hit damage
 */
void Player::hit()
{
    this->health -= 10;
}

/**
 * @brief Get player health
 */
int Player::get_health()
{
    return this->health;
}

/**
 * @brief Get player max health
 */
int Player::get_max_health()
{
    return this->MAX_HEALTH;
}

/**
 * @brief Set player health
 */
void Player::set_health(int health)
{
    this->health = health;
}
