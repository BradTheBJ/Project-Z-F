#pragma once
#include <SFML/Graphics.hpp>
#include "globals.hpp"

struct PlayerVars {
    float speed = 500.0f;
    int width = 100;
    int height = 100;
    float x = 500.0f;
    float y = 500.0f;
    bool isColliding;
};

class Player {
    private:
    sf::RectangleShape shape;
    bool isColliding;

    public:
    Player();
    PlayerVars vars;
    void update();
    void draw(sf::RenderWindow &window);
};