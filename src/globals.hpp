#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "player.hpp" 

class Enemy; 

extern float deltaTime;
extern std::vector<Enemy> enemies;
extern std::vector<Player::Gun::Bullets> playerProjectiles;
extern sf::View camera;
