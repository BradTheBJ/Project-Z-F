#include "player.hpp"

Player::Player() {
    shape.setSize({static_cast<float>(playerVars.width), static_cast<float>(playerVars.height)});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(playerVars.x, playerVars.y));
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        playerVars.x -= playerVars.speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        playerVars.x += playerVars.speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        playerVars.y -= playerVars.speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        playerVars.y += playerVars.speed * deltaTime;
    }
    
    shape.setPosition(sf::Vector2f(playerVars.x, playerVars.y));
}
void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}