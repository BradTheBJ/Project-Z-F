#pragma once
#include <SFML/Graphics.hpp>

struct EnemyVars {
    int width  = 100;
    int height = 100;
    float x    = 300.0f;
    float y    = 300.0f;
};

class Enemy {
private:
    sf::RectangleShape shape;

public:
    Enemy(int width = EnemyVars().width,
          int height = EnemyVars().height,
          float x = EnemyVars().x,
          float y = EnemyVars().y);

    sf::FloatRect getGlobalBounds() const;
    void update();
    void draw(sf::RenderWindow& window);
};
