/**
 * @file healthbars.cpp
 * @brief Health bar class implementation file
 * @author Lucas Arena
 * @version 0.1
 */

#include "healthbars.hpp"

/**
 * @brief Construct a new Health Bar:: Health Bar object
 */
HealthBar::HealthBar(sf::Vector2f position)
{
    // variables for the health bar
    this->border.setSize(sf::Vector2f(WIDTH, HEIGHT));
    this->border.setFillColor(sf::Color::Black);
    this->border.setOutlineThickness(1.f);
    this->border.setOutlineColor(sf::Color::White);
    this->bar.setSize(sf::Vector2f(WIDTH - 2.f, HEIGHT - 2.f));
    this->bar.setFillColor(sf::Color::Red);

    this->setPosition(position);
}

/**
 * @brief Update the health bar
 */
void HealthBar::update(float health_percentage)
{
    this->bar.setSize(sf::Vector2f((WIDTH - 2.f) * health_percentage, HEIGHT - 2.f));
}

/**
 * @brief Render the health bar
 */
void HealthBar::render(sf::RenderTarget *target)
{
    target->draw(this->border);
    target->draw(this->bar);
}

/**
 * @brief Set the position of the health bar
 */
void HealthBar::setPosition(sf::Vector2f position)
{
    this->border.setPosition(position);
    this->bar.setPosition(position + sf::Vector2f(1.f, 1.f));
}