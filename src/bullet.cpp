#include "bullet.hpp"
#include <cmath>
#include <iostream>
#include "globals.hpp"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f target_pos)
{
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
    this->position += this->velocity * dt;
    this->shape.setPosition(this->position);

    if (this->position .x < 0.0 || this->position.x > WIDTH || this->position.y < 0.0 || this->position.y > HEIGHT) {
        set_dead(true);
    }
}

void Bullet::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

sf::FloatRect Bullet::getGlobalBounds()
{
    return this->shape.getGlobalBounds();
}

bool Bullet::is_dead()
{
    return this->dead;
}

void Bullet::set_dead(bool dead)
{
    if (this->dead)
        return;
    this->dead = dead;
    this->shape.setScale(0.f, 0.f);
}
