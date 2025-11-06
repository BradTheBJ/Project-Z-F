#include "enemy.hpp"

// Constructor now takes width, height, x, y in this order
Enemy::Enemy(int width, int height, float x, float y) {
    shape.setSize({static_cast<float>(width), static_cast<float>(height)});
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(x, y));
}

void Enemy::update() {
    // Logic for updating enemy (if any)
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
