#pragma once
#include "Personaje.h"
#include "Bullets.hpp"

class Player : public Personaje {
    unsigned int reload_time;
    unsigned int score;
    std::vector<Bullet> bullets;
    sf::Texture bullet_texture;
    sf::Sprite bullet_sprite;

public:
    Player();

    void draw(sf::RenderWindow& window) override;
    void update() override;

    int sizeBullets();
    std::vector<Bullet> returnBullets();
    void checkCollisions(std::vector<Enemy>& enemies);
    unsigned int returnScore() const;
};
