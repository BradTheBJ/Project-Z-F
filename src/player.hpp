#pragma once
#include <SFML/Graphics.hpp>

struct PlayerVars {
    float speed  = 500.f;
    int width    = 100;
    int height   = 100;
    float x      = 500.f;
    float y      = 500.f;
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
    sf::Vector2f getPosition() const { return shape.getPosition(); }
    sf::FloatRect getGlobalBounds() const { return shape.getGlobalBounds(); }
};
