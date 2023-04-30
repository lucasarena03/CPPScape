/**
 * @file bullet.cpp
 * @brief Bullet class implementation file
 * @author Lucas Arena
 * @version 0.1
 */
#include "bullet.hpp"
#include <cmath>
#include <iostream>

#include "globals.hpp"

/**
 * @brief Bullet constructor
 */
Bullet::Bullet(sf::Vector2f pos, sf::Vector2f target_pos)
{
    // Position
    this->position = pos;
    sf::Vector2f direction = target_pos - position;
    float magnitude = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (magnitude)
    {
        direction = direction / magnitude;
    }
    this->velocity = direction * SPEED;
    this->shape.setSize(sf::Vector2f(10.f, 10.f));
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setPosition(this->position);
}

void Bullet::update(float dt)
{
    // Update the bullet position
    this->position += this->velocity * dt;
    this->shape.setPosition(this->position);

    // Check if the bullet is out of bounds
    if (this->position.x < 0.0 || this->position.x > W_WIDTH || this->position.y < 0.0 || this->position.y > W_HEIGHT)
    {
        set_dead(true);
    }
}

/**
 * @brief Render the bullet
 */
void Bullet::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

/**
 * @brief Get the global bounds of the bullet
 */
sf::FloatRect Bullet::getGlobalBounds()
{
    return this->shape.getGlobalBounds();
}

/**
 * @brief Check if the bullet is dead
 */
bool Bullet::is_dead()
{
    return this->dead;
}

/**
 * @brief Set the dead state of the bullet
 */
void Bullet::set_dead(bool dead)
{
    if (this->dead)
        return;
    this->dead = dead;
    this->shape.setScale(0.f, 0.f);
}
