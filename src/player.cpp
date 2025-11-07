#include "player.hpp"
#include "globals.hpp"
#include "enemy.hpp"

Gun::Gun() {
    shape.setRadius(static_cast<float>(vars.radius));
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin({ shape.getRadius(), shape.getRadius() });
}

void Gun::update(const sf::Vector2f& playerPos) {
    shape.setPosition(playerPos);
}

void Gun::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

Player::Player() {
    shape.setSize({ static_cast<float>(vars.width),
                    static_cast<float>(vars.height) });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ vars.x, vars.y });
    shape.setOrigin({ shape.getSize().x / 2.f,
                      shape.getSize().y / 2.f });
}

void Player::update() {
    sf::Vector2f lastPos = shape.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        vars.x -= vars.speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        vars.x += vars.speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        vars.y -= vars.speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        vars.y += vars.speed * deltaTime;
    }

    shape.setPosition({ vars.x, vars.y });
    gun.update(shape.getPosition());

    for (auto& e : enemies) {
        if (shape.getGlobalBounds().findIntersection(e.getGlobalBounds())) {
            shape.setPosition(lastPos);
            vars.x = lastPos.x;
            vars.y = lastPos.y;
            break;
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
    gun.draw(window);
}
