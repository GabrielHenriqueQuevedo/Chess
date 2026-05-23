#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <bitset>

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
    public:
        bool isLegalMove(int startX, int startY, int endX, int endY) override {
            Piece::isLegalMove(startX, startY, endX, endY);
        }
        virtual sf::RectangleShape createPiece(sf::Color color) override {
            sf::RectangleShape piece = Piece::createPiece(color);
        }
};

class Knight : public Piece {
    public:
        bool isLegalMove(int startX, int startY, int endX, int endY) override {
            Piece::isLegalMove(startX, startY, endX, endY);
        }
        virtual sf::RectangleShape createPiece(sf::Color color) override {
            sf::RectangleShape piece = Piece::createPiece(color);
        }
};

class Rook : public Piece {
    public:
        bool isLegalMove(int startX, int startY, int endX, int endY) override {
            Piece::isLegalMove(startX, startY, endX, endY);
        }
        virtual sf::RectangleShape createPiece(sf::Color color) override {
            sf::RectangleShape piece = Piece::createPiece(color);
        }
};

class Queen : public Piece {
    public:
        bool isLegalMove(int startX, int startY, int endX, int endY) override {
            Piece::isLegalMove(startX, startY, endX, endY);
        }
        virtual sf::RectangleShape createPiece(sf::Color color) override {
            sf::RectangleShape piece = Piece::createPiece(color);
        }
};

class King : public Piece {
    public:
        bool isLegalMove(int startX, int startY, int endX, int endY) override {
            Piece::isLegalMove(startX, startY, endX, endY);
        }
        virtual sf::RectangleShape createPiece(sf::Color color) override {
            sf::RectangleShape piece = Piece::createPiece(color);
        }
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

    /*
    HEX - linhas:
    8  7  6  5  4  3  2  1
    00 00 00 00 00 00 00 00
    */

    uint64_t w_pawns   = 0x00'00'00'00'00'00'FF'00ULL;
    uint64_t w_bishops = 0x00'00'00'00'00'00'00'24ULL;
    uint64_t w_knights = 0x00'00'00'00'00'00'00'42ULL;
    uint64_t w_rooks   = 0x00'00'00'00'00'00'00'81ULL;
    uint64_t w_queens  = 0x00'00'00'00'00'00'00'01ULL;
    uint64_t w_king    = 0x00'00'00'00'00'00'00'80ULL;
    
    uint64_t b_pawns   = 0x00'FF'00'00'00'00'00'00ULL;
    uint64_t b_bishops = 0x24'00'00'00'00'00'00'00ULL;
    uint64_t b_knights = 0x42'00'00'00'00'00'00'00ULL;
    uint64_t b_rooks   = 0x81'00'00'00'00'00'00'00ULL;
    uint64_t b_queens  = 0x01'00'00'00'00'00'00'00ULL;
    uint64_t b_king    = 0x80'00'00'00'00'00'00'00ULL;

    uint64_t allWhites = w_pawns | w_bishops | w_knights | w_rooks | w_queens | w_king;
    uint64_t allBlacks = b_pawns | b_bishops | b_knights | b_rooks | b_queens | b_king;

    uint64_t allPieces = allWhites | allBlacks;

    uint64_t de = 1ULL << 8;
    uint64_t para = de << 8;

    if (w_pawns & de) {
        w_pawns &= ~de;
        w_pawns |= para;
    }

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