/**
 * @file main.cpp
 * @brief Main file for the game
 * @author Lucas Arena
 * @version 0.1
 */

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
#include "globals.hpp"
#include "healthbars.hpp"
#include "ground.hpp"

// Window
sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Runescape!", sf::Style::Close | sf::Style::Resize);
sf::Clock timeClock;

// Game objects
Player player;
Enemy enemy;
Ground ground;
HealthBar enemy_health_bar(sf::Vector2f(10.f, 10.f));

// Functions
static void render();
static void update();

int main()
{
    // Game loop
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

/**
 * @brief Render all game objects
 */
static void render()
{
    // Render
    window.clear();
    ground.render(&window);
    if (!enemy.is_dead())
        enemy.render(&window);
    if (!player.is_dead())
        player.render(&window);
    enemy_health_bar.render(&window);
    window.display();
}

/**
 * @brief Update all game objects
 */
static void update()
{
    // Update clock
    sf::Time elapsed = timeClock.restart();
    float dt = elapsed.asSeconds();

    // Mouse input
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        player.move(sf::Vector2f(mousePos.x, mousePos.y));
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        player.shoot(sf::Vector2f(mousePos.x, mousePos.y));
    }

    // Update game objects
    if (!player.is_dead())
        player.update(dt, &enemy);
    if (!enemy.is_dead())
        enemy.update(dt, &player);
    enemy_health_bar.update((float)enemy.get_health() / enemy.get_max_health());
}