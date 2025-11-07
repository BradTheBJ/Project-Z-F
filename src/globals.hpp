#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "player.hpp"
#include "enemy.hpp"

extern float deltaTime;
extern std::vector<Enemy> enemies;
extern std::vector<Player> playerProjectiles;

extern sf::View camera;
