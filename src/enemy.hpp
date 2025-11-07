#pragma once
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "player.hpp"
#include <cmath>

struct EnemyVars {
    int width = 100;
    int height = 100;
    float x = 300.f;
    float y = 300.f;
    float speed = 300.f;
};

class Enemy {
private:
    sf::RectangleShape shape;
    EnemyVars eVars;

public:
    Enemy(int width = EnemyVars().width,
          int height = EnemyVars().height,
          float x = EnemyVars().x,
          float y = EnemyVars().y);

    sf::FloatRect getGlobalBounds() const;
    void update(const Player& player);
    void draw(sf::RenderWindow& window);
};
