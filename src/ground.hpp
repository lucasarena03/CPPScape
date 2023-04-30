/**
 * @file ground.hpp
 * @brief Ground class for the game
 * @author Lucas Arena
 * @version 0.1
 */

#ifndef GROUND_HPP
#define GROUND_HPP

#include "player.hpp"
#include "bullet.hpp"
#include "globals.hpp"

#include <SFML/Graphics.hpp>

class Ground
{
private:
    // variables
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f target_position;
    sf::Vector2f position;

public:
    // functions
    Ground();
    ~Ground();
    void render(sf::RenderTarget *target);
};

#endif