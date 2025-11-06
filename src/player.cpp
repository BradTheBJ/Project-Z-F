#include "player.hpp"

Player::Player() {
    shape.setSize({static_cast<float>(vars.width), static_cast<float>(vars.height)});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(vars.x, vars.y));
}

bool isColliding = false;

void Player::update() {
    sf::Vector2f lastPos = shape.getPosition();

    // Handle movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        vars.x -= vars.speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        vars.x += vars.speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        vars.y -= vars.speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        vars.y += vars.speed * deltaTime;

    // Update shape position before collision check
    shape.setPosition(sf::Vector2f(vars.x, vars.y));

    // Single collision block
    bool isColliding = false;
    sf::FloatRect intersection;
    for (Enemy& e : enemies) {
        if (shape.getGlobalBounds().findIntersection(e.getGlobalBounds())) {
            isColliding = true;
            break; // stop at first collision
        }
    }

    // Undo movement if colliding
    if (isColliding) {
        shape.setPosition(lastPos);
        vars.x = lastPos.x;
        vars.y = lastPos.y;
    }
}


void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}
