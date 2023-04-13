#include "healthbars.hpp"

//Enemy health bar
HealthBar::HealthBar(sf::Vector2f position)
{
    this->border.setSize(sf::Vector2f(WIDTH, HEIGHT));
    this->border.setFillColor(sf::Color::Black);
    this->border.setOutlineThickness(1.f);
    this->border.setOutlineColor(sf::Color::White);

    this->bar.setSize(sf::Vector2f(WIDTH - 2.f, HEIGHT - 2.f));
    this->bar.setFillColor(sf::Color::Red);

    this->setPosition(position);
}

void HealthBar::update(float health_percentage)
{
    this->bar.setSize(sf::Vector2f((WIDTH - 2.f) * health_percentage, HEIGHT - 2.f));
}

void HealthBar::render(sf::RenderTarget *target)
{
    target->draw(this->border);
    target->draw(this->bar);
}

void HealthBar::setPosition(sf::Vector2f position)
{
    this->border.setPosition(position);
    this->bar.setPosition(position + sf::Vector2f(1.f, 1.f));
}