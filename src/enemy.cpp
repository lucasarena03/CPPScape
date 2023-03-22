#include "enemy.hpp"

#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>

#include "globals.hpp"

Enemy::Enemy()
{
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(WIDTH / 2.f, HEIGHT / 2.f);
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt, Player *player)
{
    sf::Vector2f player_pos = player->getPosition();
    sf::Vector2f direction = player_pos - this->position;
    float distance = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (distance)
    {
        direction = direction / distance;
    }
    this->velocity = direction * SPEED;
    this->position += this->velocity * dt;
    this->shape.setPosition(this->position);

    // check for collision with player bullets
    for (auto &bullet : player->getBullets())
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

    if (this->shoot_timer.getElapsedTime().asSeconds() >= this->SHOOT_INTERVAL)
    {
        this->shoot_timer.restart();
        attacks = (attacks + 1) % 3;
        if (attacks == 0)
        {
            this->special_attack(player_pos);
        }
        else
        {
            this->shoot(player_pos);
        }
    }
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

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
    for (auto &bullet : bullets)
    {
        bullet.render(target);
    }
}

void Enemy::move(sf::Vector2f target_position)
{
    sf::Vector2f direction = target_position - this->position;
    float distance = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    if (distance)
    {
        direction = direction / distance;
    }
    this->velocity = direction * SPEED;
    this->position += this->velocity;
    this->shape.setPosition(this->position);
}

bool Enemy::is_dead()
{
    return this->health <= 0;
}

void Enemy::set_dead(bool dead)
{
    if (dead)
    {
        this->health = 0;
    }
}

void Enemy::hit()
{
    this->health -= 10;
}

int Enemy::get_health()
{
    return this->health;
}

int Enemy::get_max_health()
{
    return this->MAX_HEALTH;
}

void Enemy::set_health(int health)
{
    this->health = health;
}

// Enemy shoot function
void Enemy::shoot(sf::Vector2f target_pos)
{
    this->bullets.push_back(Bullet(this->position, target_pos));
}

void Enemy::special_attack(sf::Vector2f target_pos)
{
    for (int i = 0; i < 5; i++)
    {
        this->bullets.push_back(Bullet(this->position, target_pos));
        target_pos += sf::Vector2f(rand() % 70 - 35, rand() % 70 - 35);
    }
}

std::vector<Bullet> &Enemy::getBullets()
{
    return this->bullets;
}
