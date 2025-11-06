#pragma once
#include <SFML/Graphics.hpp>

struct EnemyVars {
    int width = 100;
    int height = 100;
    float x = 300.0f;
    float y = 300.0f;
};

class Enemy {
private:
    sf::RectangleShape shape;

public:
    // Constructor now takes width, height first, followed by x and y
    Enemy(int width = EnemyVars().width, int height = EnemyVars().height, float x = EnemyVars().x, float y = EnemyVars().y);

    // In enemy.hpp, inside class Enemy
    sf::FloatRect getGlobalBounds() const {
        return shape.getGlobalBounds();
    }


    void update();
    void draw(sf::RenderWindow& window);
};
