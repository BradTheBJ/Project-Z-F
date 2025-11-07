#include "enemy.hpp"

Enemy::Enemy(int width, int height, float x, float y) {
    shape.setSize({ static_cast<float>(width),
                    static_cast<float>(height) });
    shape.setFillColor(sf::Color::Red);
    shape.setPosition({ x, y });
}

sf::FloatRect Enemy::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

void Enemy::update() {
    // Enemy logic if needed
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
