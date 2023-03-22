
#include "player.hpp"
#include <iostream>
#include <cmath>
#include <vector>

Player::Player()
{
    this->position = sf::Vector2f(0.f, 0.f);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->shape.setSize(sf::Vector2f(32.f, 32.f));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(this->position);
}

Player::~Player()
{
}

void Player::update(float dt)
{
    // Calculate the velocity from the target position and current position
    sf::Vector2f direction = target_position - position;
    float magnitude = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (magnitude)
    {
        direction = direction / magnitude;
    }
    this->velocity = direction * SPEED;
    // Update the position
    this->position += this->velocity * dt;
    this->shape.setPosition(this->position);

    // Update all bullets
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

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);

    for (auto &bullet : bullets)
    {
        bullet.render(target);
    }
}

void Player::move(sf::Vector2f target_positon)
{
    this->target_position = target_positon;
}

void Player::shoot(sf::Vector2f target_position)
{
    if (this->shoot_timer.getElapsedTime().asMilliseconds() < SHOOT_INTERVAL)
    {
        return;
    }
    Bullet bullet(this->position + sf::Vector2f(11, 11), target_position);
    this->bullets.push_back(bullet);
    this->shoot_timer.restart();
}

std::vector<Bullet> &Player::getBullets()
{
    return this->bullets;
}

