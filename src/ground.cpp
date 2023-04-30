/**
 * @file ground.cpp
 * @brief Ground class implementation file
 * @author Lucas Arena
 * @version 0.1
 */

#include "ground.hpp"
#include "globals.hpp"
#include <iostream>

/**
 * @brief Ground constructor
 */
Ground::Ground()
{
    // variables and sprite
    this->position = sf::Vector2f(0.f, 0.f);
    this->target_position = this->position;
    if (!this->texture.loadFromFile("assets\\ground.png"))
    {
        std::cout << "Error loading player texture" << std::endl;
    }
    // Scale the sprite to the window size
    this->sprite.setTexture(this->texture);
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(W_WIDTH / sprite.getGlobalBounds().width, W_HEIGHT / sprite.getGlobalBounds().height);
}

/**
 * @brief Render the ground
 */
void Ground::render(sf::RenderTarget *target)
{
    target->draw(sprite);
}

/**
 * @brief Ground destructor
 */
Ground::~Ground()
{
}
