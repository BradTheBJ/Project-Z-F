#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Enemy;  // forward declaration
class Player; // forward declaration

extern float deltaTime;
extern std::vector<Enemy> enemies;
extern std::vector<Player> playerProjectiles;
extern sf::View camera;
