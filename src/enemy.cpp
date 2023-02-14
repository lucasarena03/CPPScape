#include "enemy.hpp"

#include <iostream>
#include <cmath>


Enemy::Enemy()
{
    this->position = sf::Vector2f(0.f, 0.f);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->shape.setSize(sf::Vector2f(100.f, 100.f));
    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setPosition(this->position);
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt, Player*player)
{
    // Calculate the velocity from the target position and current position
    sf::Vector2f direction = player->getPosition() - position;
    float magnitude = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (magnitude){
    direction = direction / magnitude;
    }
    this->velocity = direction * SPEED;
    //Update the position
    this->position += this->velocity * dt;
    this->shape.setPosition(this->position);
    std::cout << position.x << " " << position.y << std::endl;
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

