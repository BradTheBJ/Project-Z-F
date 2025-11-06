#pragma once
#include <SFML/Graphics.hpp>
#include "globals.hpp"

struct EnemyVars
{
    int width = 100;
    int height = 100;
    float x = 300.0f;
    float y = 300.0f;
};

class Enemy {
private:
    sf::RectangleShape shape;

public:
    Enemy();
    EnemyVars e;
    void update();
    void draw(sf::RenderWindow &window);
};

