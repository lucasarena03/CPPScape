/**
 * @file healthbars.hpp
 * @brief Health bar class for the game
 * @author Lucas Arena
 * @version 0.1
 */

#ifndef HEALTHBARS_HPP
#define HEALTHBARS_HPP

#include <SFML/Graphics.hpp>

class HealthBar
{
private:
    // variables
    const float HEIGHT = 10.f;
    sf::RectangleShape border;
    sf::RectangleShape bar;

public:
    const float WIDTH = 100.f;
    HealthBar(sf::Vector2f position);
    // functions
    void update(float health_percentage);
    void render(sf::RenderTarget *target);
    void setPosition(sf::Vector2f position);
};

#endif