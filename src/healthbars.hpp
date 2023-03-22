#ifndef HEALTHBARS_HPP
#define HEALTHBARS_HPP

#include <SFML/Graphics.hpp>

class HealthBar
{
private:
    const float WIDTH = 100.f;
    const float HEIGHT = 10.f;

    sf::RectangleShape border;
    sf::RectangleShape bar;

public:
    HealthBar(sf::Vector2f position);
    void update(float health_percentage);
    void render(sf::RenderTarget *target);
};

#endif