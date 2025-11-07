#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.hpp"

struct PlayerVars {
    float speed  = 500.0f;
    int width    = 100;
    int height   = 100;
    float x      = 500.0f;
    float y      = 500.0f;
};

class Gun {
private:
    sf::CircleShape shape;

public:
    struct GunVars {
        int radius = 40;
    };
    GunVars vars;

    Gun();
    void update(const sf::Vector2f& playerPos);
    void draw(sf::RenderWindow& window);
};

class Player {
private:
    sf::RectangleShape shape;
    Gun gun;

public:
    PlayerVars vars;

    Player();
    void update();
    void draw(sf::RenderWindow& window);
};
