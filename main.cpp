#include <SFML/Graphics.hpp>
#include <string>

class Piece {
    public:
        virtual bool isLegalMove(int startX, int startY, int endX, int endY) {
            return false;
        }
        virtual sf::RectangleShape createPiece(sf::Color color) {
            sf::RectangleShape piece = sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
            piece.setFillColor(color);
            return piece;
        }
};

class Pawn : public Piece {
    public:
        bool isLegalMove(int startX, int startY, int endX, int endY) override {
            Piece::isLegalMove(startX, startY, endX, endY);
        }
        virtual sf::RectangleShape createPiece(sf::Color color) override {
            sf::RectangleShape piece = Piece::createPiece(color);
        }

};

class Bishop : public Piece {

};

class Knight : public Piece {

};

class Rook : public Piece {

};

class Queen : public Piece {

};

class King : public Piece {

};

sf::RectangleShape createSquare(float x, float y, sf::Color color);

int main() {

    /*
    57 58 59 60 61 62 63 64
    49 50 51 52 53 54 55 56
    41 42 43 44 45 46 47 48
    33 34 35 36 37 38 39 40
    25 26 27 28 29 30 31 32
    17 18 19 20 21 22 23 24
    9  10 11 12 13 14 15 16
    1  2  3  4  5  6  7  8
    */

    uint64_t w_pawns;
    uint64_t w_bishops;
    uint64_t w_knights;
    uint64_t w_rooks;
    uint64_t w_queens;
    uint64_t w_king;
    
    uint64_t b_pawns;
    uint64_t b_bishops;
    uint64_t b_knights;
    uint64_t b_rooks;
    uint64_t b_queens;
    uint64_t b_king;

    uint64_t allWhites;
    uint64_t allBlacks;

    uint64_t allPieces = allWhites | allBlacks;

    // board |= (1ULL << square_index);

    // No SFML 3, passamos um sf::Vector2u dentro do VideoMode
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Chess Game");
    
    window.setFramerateLimit(60);

    sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
    square.setFillColor(sf::Color::Black);

    sf::RectangleShape square2 = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
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
                    sf::RectangleShape square = createSquare(i * 50.0f, j * 50.0f, sf::Color::White);
                    window.draw(square);
                } else {
                    sf::RectangleShape square = createSquare(i * 50.0f, j * 50.0f, sf::Color::Black);
                    window.draw(square);
                }
            }
        }
        window.display();
    }
}

sf::RectangleShape createSquare(float x, float y, sf::Color color) {
    sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
    square.setFillColor(color);
    square.setPosition(sf::Vector2f(x, y));
    return square;
}