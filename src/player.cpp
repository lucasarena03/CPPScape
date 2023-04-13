#include "player.hpp"

#include <iostream>
#include <cmath>
#include <vector>

#include "globals.hpp"
#include "enemy.hpp"

Player::Player()
{
    this->position = sf::Vector2f(0.f, 0.f);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->shape.setSize(sf::Vector2f(WIDTH, HEIGHT));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(this->position);
}

Player::~Player()
{
}

void Player::update(float dt, Enemy *enemy)
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

    for (auto &bullet : enemy->getBullets())
    {
        if (bullet.is_dead())
        {
            continue;
        }
        if (bullet.getGlobalBounds().intersects(this->shape.getGlobalBounds()))
        {
            bullet.set_dead(true);
            this->hit();
        }
    }

    //Check if player is dead and remove from screen
    if (this->health <= 0)
    {
        this->set_dead(true);
    }

    healthbar.setPosition(sf::Vector2f(this->position.x + WIDTH / 2 - healthbar.WIDTH / 2, this->position.y - 20));

    healthbar.update(this->health / (float)this->MAX_HEALTH);
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);

    for (auto &bullet : bullets)
    {
        bullet.render(target);
    }

    //if player is dead, remove it screen
    if (this->is_dead())
    {
        this->shape.setPosition(-100, -100);
        this->bullets.clear();
    }

    healthbar.render(target);
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

bool Player::is_dead()
{
    return this->health <= 0;
}

void Player::set_dead(bool dead)
{
    if (dead)
    {
        this->health = 0;
    }
}

void Player::hit()
{
    this->health -= 10;
}

int Player::get_health()
{
    return this->health;
}

int Player::get_max_health()
{
    return this->MAX_HEALTH;
}

void Player::set_health(int health)
{
    this->health = health;
}





