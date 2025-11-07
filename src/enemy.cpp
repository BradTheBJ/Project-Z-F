#include "enemy.hpp"
#include "globals.hpp"
#include "player.hpp"

Enemy::Enemy(int width, int height, float x, float y) {
    shape.setSize({ static_cast<float>(width),
                    static_cast<float>(height) });
    shape.setFillColor(sf::Color::Red);
    shape.setPosition({ x, y });
    shape.setOrigin({ shape.getSize().x / 2.f,
                      shape.getSize().y / 2.f });
}

sf::FloatRect Enemy::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

void Enemy::update(const Player& player) {
    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f dir = player.getPosition() - pos;
    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (length != 0.f) {
        dir /= length;
        pos += dir * eVars.speed * deltaTime;
        shape.setPosition(pos);
    }
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
