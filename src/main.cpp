#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>

#include "player.hpp"
#include "enemy.hpp"

sf::RenderWindow window(sf::VideoMode(512, 512), "Runescape!", sf::Style::Close | sf::Style::Resize);
sf::Clock timeClock;

Player player;
Enemy enemy;

static void render();
static void update();

int main()
{

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        update();
        render();
    }

    return 0;
}

static void render()
{
    window.clear();
    enemy.render(&window);
    player.render(&window);
    window.display();
}

static void update()
{
    sf::Time elapsed = timeClock.restart();
    float dt = elapsed.asSeconds();

    // movement handling
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        player.move(sf::Vector2f(mousePos.x, mousePos.y));
    }

    // update player AND ENEMY
    player.update(dt);
    enemy.update(dt, &player);


    // Player can shoot bullets at the enemy
    // sf::RectangleShape bullet(sf::Vector2f(10.f, 10.f));
    // bullet.setFillColor(sf::Color::Green);
    // bullet.setPosition(player.getPosition());

    // if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    // {
    //     sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    //     sf::Vector2f playerPos = player.getPosition();
    //     sf::Vector2f direction = sf::Vector2f(mousePos.x - playerPos.x, mousePos.y - playerPos.y);
    //     float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));
    //     if (length != 0)
    //     {
    //         direction.x /= length;
    //         direction.y /= length;
    //     }
    //     bullet.move(.30f * direction);
    // }
}