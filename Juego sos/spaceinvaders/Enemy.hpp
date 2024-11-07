#pragma once
#include "Personaje.h"

class Enemy : public Personaje {
    bool direction;
    bool dead;

public:
    Enemy();
    Enemy(const sf::Texture& tex, unsigned short fx, unsigned short fy, unsigned short spd);

    void draw(sf::RenderWindow& window) override;
    void update() override;

    void set_dead(int i);
    unsigned short get_dead() const;

    void setColor(sf::Color color);
    sf::Color getColor() const;
};
