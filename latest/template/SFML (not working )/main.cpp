#include <SFML/Graphics.hpp>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Your rendering logic here
        window.clear(sf::Color::Black);
        // Draw shapes, sprites, etc.
        window.display();
    }
    return 0;
}
