/**
 * @file weapon.hpp
 * @brief Weapon class for the game
 * @author Lucas Arena
 * @version 0.1
 */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <SFML/Graphics.hpp>

#include "bullet.hpp"

class Weapon
{
private:
    // variables
    std::vector<Bullet> bullets;

public:
    // functions
    Weapon();
    ~Weapon();
    void update(float dt);
    void render(sf::RenderTarget *target);
    std::vector<Bullet> &getBullets();
};

#endif