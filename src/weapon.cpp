/**
 * @file weapon.cpp
 * @brief Weapon class implementation file
 * @author Lucas Arena
 * @version 0.1
 */

#include "weapon.hpp"

/**
 * @brief Weapon constructor
 */
Weapon::Weapon()
{
}

/**
 * @brief Weapon destructor
 */

Weapon::~Weapon()
{
}

/**
 * @brief Update the weapon
 */
void Weapon::update(float dt)
{
    // Update bullets
    for (int i = 0; i < this->bullets.size(); i++)
    {
        Bullet &bullet = bullets[i];
        bullet.update(dt);

        if (bullet.is_dead())
        {
            bullets.erase(bullets.begin() + i--);
        }
    }
}

/**
 * @brief Render the weapon
 */
void Weapon::render(sf::RenderTarget *target)
{
    // Render bullets
    for (auto &bullet : this->bullets)
    {
        bullet.render(target);
    }
}

/**
 * @brief Get the bullets
 */
std::vector<Bullet> &Weapon::getBullets()
{
    return this->bullets;
}
