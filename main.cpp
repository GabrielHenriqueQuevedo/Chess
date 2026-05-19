#include <SFML/Graphics.hpp>

sf::RectangleShape createSquare(float x, float y, sf::Color color);

int main() {
    // No SFML 3, passamos um sf::Vector2u dentro do VideoMode
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Chess Game");
    
    window.setFramerateLimit(20);

    sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    square.setFillColor(sf::Color::Black);

    sf::RectangleShape square2 = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    square2.setFillColor(sf::Color::White);
    square2.setPosition(sf::Vector2f(50.f, 50.f));

    // Loop principal
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>() ||
             (event->is<sf::Event::KeyPressed>() &&
              event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)) {
                window.close();
            }
        }

        window.clear(sf::Color(21, 21, 21));

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if ((i + j) % 2 == 0) {
                    sf::RectangleShape square = createSquare(i * 50.f, j * 50.f, sf::Color::White);
                    window.draw(square);
                } else {
                    sf::RectangleShape square = createSquare(i * 50.f, j * 50.f, sf::Color::Black);
                    window.draw(square);
                }
            }
        }
        window.display();
    }
}

sf::RectangleShape createSquare(float x, float y, sf::Color color) {
    sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    square.setFillColor(color);
    square.setPosition(sf::Vector2f(x, y));
    return square;
}