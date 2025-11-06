#include "enemy.hpp"

Enemy::Enemy() {
    shape.setSize({static_cast<float>(e.width), static_cast<float>(e.height)});
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(e.x, e.y));
}

void Enemy::update() {
    // Enemy update logic can be added here
}
void Enemy::draw(sf::RenderWindow &window) {
    window.draw(shape);
}