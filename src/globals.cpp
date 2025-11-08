#include "globals.hpp"
#include "enemy.hpp"
#include "player.hpp"

float deltaTime = 0.f;
std::vector<Enemy> enemies;
std::vector<Player::Gun::Bullets> playerProjectiles;
sf::View camera;
