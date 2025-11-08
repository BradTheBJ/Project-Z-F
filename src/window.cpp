// src/window.cpp
#include "window.hpp"
#include "globals.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include <algorithm>

void game() {
    Window w;
    Player player;

    sf::VideoMode mode(sf::Vector2u(static_cast<unsigned int>(w.width),
                                     static_cast<unsigned int>(w.height)));
    sf::RenderWindow window(mode, "Project Z");

    window.setVerticalSyncEnabled(true);

    camera.setSize(static_cast<sf::Vector2f>(window.getSize()));
    camera.setCenter(player.getPosition());
    window.setView(camera);

    enemies.clear();
    enemies.push_back(Enemy());
    enemies.push_back(Enemy(100, 100, 100, 100));

    sf::Clock clock;

    while (window.isOpen()) {
    deltaTime = clock.restart().asSeconds();

    // handle events
    while (auto eventOpt = window.pollEvent()) {
        const sf::Event &event = *eventOpt;

        if (event.is<sf::Event::Closed>()) {
            window.close();
        }
        else if (const auto* kp = event.getIf<sf::Event::KeyPressed>()) {
            if (kp->code == sf::Keyboard::Key::Escape) {
                window.close();
            }
        }
    }

    // updates
    player.update(window);
    for (auto &e : enemies) {
        e.update(player);
    }

    // cleanup
    playerProjectiles.erase(
        std::remove_if(playerProjectiles.begin(), playerProjectiles.end(),
                       [](auto &b){ return b.destroyed; }),
        playerProjectiles.end()
    );
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
                       [](auto &e){ return !e.isAlive(); }),
        enemies.end()
    );

    // camera & draw
    camera.setCenter(player.getPosition());
    window.setView(camera);

    window.clear(sf::Color::Black);
    player.draw(window);
    for (auto &e : enemies) {
        e.draw(window);
    }
    window.display();
}
}
