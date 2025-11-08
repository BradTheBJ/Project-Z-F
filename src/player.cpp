// src/player.cpp
#include "player.hpp"
#include "globals.hpp"
#include "enemy.hpp"
#include <SFML/Window/Mouse.hpp>
#include <cmath>

// ---------------- Bullets ----------------
Player::Gun::Bullets::Bullets() {
    bullet.setRadius(static_cast<float>(bVars.radius));
    bullet.setFillColor(sf::Color::Yellow);
    bullet.setOrigin({ bullet.getRadius(), bullet.getRadius() });
    destroyed = false;
}

sf::FloatRect Player::Gun::Bullets::getGlobalBounds() const {
    return bullet.getGlobalBounds();
}

void Player::Gun::Bullets::moveTowards(const sf::Vector2f& target, float dt) {
    sf::Vector2f pos = bullet.getPosition();
    sf::Vector2f dir = target - pos;
    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (length != 0.f) {
        dir /= length;
        pos += dir * bVars.speed * dt;
        bullet.setPosition(pos);
    }
}

// ---------------- Gun ----------------
Player::Gun::Gun() {
    shape.setRadius(static_cast<float>(vars.radius));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin({ shape.getRadius(), shape.getRadius() });
}

void Player::Gun::update(const sf::Vector2f& playerPos, sf::RenderWindow& window) {
    // Update gun position
    shape.setPosition(playerPos);

    // Shooting: spawn a bullet when left mouse button pressed
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        playerProjectiles.push_back(Bullets());
        playerProjectiles.back().bullet.setPosition(playerPos);
    }

    // Get mouse position relative to the window (world coords)
    sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window); // window-relative
    sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePixelPos); // world coords

    // Move bullets toward mouse
    for (auto& proj : playerProjectiles) {
        if (!proj.destroyed) proj.moveTowards(mouseWorldPos, deltaTime);
    }
}

void Player::Gun::draw(sf::RenderWindow& window) {
    window.draw(shape);
    for (auto& proj : playerProjectiles) {
        if (!proj.destroyed) window.draw(proj.bullet);
    }
}

// ---------------- Player ----------------
Player::Player() {
    shape.setSize({ static_cast<float>(vars.width), static_cast<float>(vars.height) });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ vars.x, vars.y });
    shape.setOrigin({ shape.getSize().x / 2.f, shape.getSize().y / 2.f });
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

void Player::update(sf::RenderWindow& window) {  
    sf::Vector2f lastPos = shape.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) vars.x -= vars.speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) vars.x += vars.speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vars.y -= vars.speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vars.y += vars.speed * deltaTime;

    shape.setPosition({ vars.x, vars.y });

    // update gun (which also moves bullets)
    gun.update(shape.getPosition(), window);

    // collision with enemies: revert to last position if collision
    for (auto& e : enemies) {
    if (!e.isAlive()) continue;
    auto playerBounds = shape.getGlobalBounds();
    auto enemyBounds  = e.getGlobalBounds();
    if ( playerBounds.findIntersection(enemyBounds).has_value() ) {

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
