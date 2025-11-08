#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Enemy; // forward declaration

struct PlayerVars {
    float speed  = 500.f;
    int width    = 100;
    int height   = 100;
    float x      = 500.f;
    float y      = 500.f;
};

class Player {
public:
    struct Gun {
        class Bullets {
        public:
            sf::CircleShape bullet;

            struct BulletVars {
                float radius = 10.f;
                float speed  = 600.f;
            } bVars;

            Bullets();
            sf::FloatRect getGlobalBounds() const;
            void moveTowards(const sf::Vector2f& target, float deltaTime);
        };

        sf::CircleShape shape;
        struct GunVars { int radius = 40; } vars;

        Gun();
        void update(const sf::Vector2f& playerPos);
        void draw(sf::RenderWindow& window);
    };

    PlayerVars vars;
private:
    sf::RectangleShape shape;
    Gun gun;

public:
    Player();
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    void update();
    void draw(sf::RenderWindow& window);
};
