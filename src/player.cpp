
#include "player.hpp"
#include <iostream>
#include <cmath>

Player::Player()
{
    this->position = sf::Vector2f(0.f, 0.f);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->shape.setSize(sf::Vector2f(100.f, 100.f));
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
    if (magnitude){
    direction = direction / magnitude;
    }
    this->velocity = direction * SPEED;
    //Update the position
    this->position += this->velocity * dt;
    this->shape.setPosition(this->position);
    std::cout << position.x << " " << position.y << std::endl;
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

void Player::move(sf::Vector2f target_positon)
{
    this->target_position = target_positon;
}