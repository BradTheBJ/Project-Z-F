#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "globals.hpp"
#include "enemy.hpp"
#include "player.hpp"

struct Window {
    int width  = 1920;
    int height = 1080;
};

void game();
