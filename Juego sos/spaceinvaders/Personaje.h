#pragma once
#include <SFML/Graphics.hpp>

class Personaje {
protected:
    unsigned short x;
    unsigned short y;
    unsigned short speed;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Color color;

public:
    Personaje(unsigned short startX, unsigned short startY, unsigned short spd, const sf::Texture& tex)
        : x(startX), y(startY), speed(spd), texture(tex) {
        sprite.setTexture(texture);
    }

    virtual void draw(sf::RenderWindow& window) {
        sprite.setPosition(x, y);
        window.draw(sprite);
    }

    virtual void update() = 0; // Método virtual puro

    // Métodos para obtener las posiciones
    unsigned short get_x() const { return x; }
    unsigned short get_y() const { return y; }
};
