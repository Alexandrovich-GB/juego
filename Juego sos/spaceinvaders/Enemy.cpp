#include "Enemy.hpp"
#include "Global.hpp"

Enemy::Enemy()
    : Personaje(50, 50, 3, texture), dead(0), direction(0) {
    color = sf::Color::Magenta;
    sprite.setColor(color);
}

Enemy::Enemy(const sf::Texture& tex, unsigned short fx, unsigned short fy, unsigned short spd)
    : Personaje(fx, fy, spd, tex), dead(0), direction(0) {
    color = sf::Color::White;
    sprite.setColor(color);
}

void Enemy::draw(sf::RenderWindow& window) {
    if (!dead) {
        Personaje::draw(window);
    }
}

void Enemy::update() {
    if (dead == 0) {
        switch (direction) {
        case 0:
            if (x < SCREEN_WIDTH - BUFFER_FR_BORDER * 2) {
                x += speed;
            }
            else {
                direction = 1;
                y += 75;
            }
            break;
        case 1:
            if (x > BUFFER_FR_BORDER) {
                x -= speed;
            }
            else {
                direction = 0;
                y += 75;
            }
            break;
        }
    }
}

void Enemy::set_dead(int i) {
    dead = i;
}

unsigned short Enemy::get_dead() const {
    return dead;
}

void Enemy::setColor(sf::Color color) {
    sprite.setColor(color);
    this->color = color;
}

sf::Color Enemy::getColor() const {
    return this->color;
}
