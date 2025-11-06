#pragma once
#include <SFML/Graphics.hpp>
#include "globals.hpp"

struct PlayerVars {
    float speed = 600.0f;
    int width = 100;
    int height = 100;
    float x = 500.0f;
    float y = 500.0f;
};

class Player {
    private:
    sf::RectangleShape shape;

    public:
    Player();
    PlayerVars playerVars;
    void update();
    void draw(sf::RenderWindow &window);
};