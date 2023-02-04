
#include <SFML/Window.hpp>

/**
 * @brief Main function
*/
int main(int argc, const char* argv[]) {

    sf::Window window(sf::VideoMode(800, 600), "My window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    
    return 0;
}
