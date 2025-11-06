#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include <SFML/System/Clock.hpp>
#include "enemy.hpp"

struct Window {
    int width = 1920;
    int height = 1080;
};

void game();