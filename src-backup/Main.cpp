#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
using namespace sf;

int main()
{
    //Make a Main Menu
    RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
    //Set background
    RectangleShape background;
    Texture Maintexture;
    if (!Maintexture.loadFromFile("./Textures/MainMenu.png")) {
        std::cout << "Error loading background" << std::endl;
    }
    background.setTexture(&Maintexture);

    //photo to the game
    RectangleShape Pbackground;
    Pbackground.setSize(Vector2f(960,720));
    Texture back_texture;
    back_texture.loadFromFile("./Textures/Background.jpg");
    Pbackground.setTexture(&back_texture);

    //Game loop
    while (MENU.isOpen())
    {
        Event event;
        while (MENU.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch (event.key.code)
                {
                case Keyboard::Up:
                    mainMenu.MoveUp();
                    break;
                case Keyboard::Down:
                    mainMenu.MoveDown();
                    break;
                case Keyboard::Return:
                    switch (mainMenu.MainMenuPressed())
                    {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        break;
                    case 1:
                        std::cout << "About button has been pressed" << std::endl;
                        break;
                    case 2:
                        MENU.close();
                        break;
                    }
                    break;
                }
                break;
            case Event::Closed:
                MENU.close();
                break;
            }
        }
        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
    }
    

    return 0;
}
