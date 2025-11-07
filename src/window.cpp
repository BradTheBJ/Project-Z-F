#include "window.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "globals.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

void game() {
    Window w;
    Player player;

    sf::VideoMode mode({ static_cast<unsigned int>(w.width),
                         static_cast<unsigned int>(w.height) });
    sf::RenderWindow window(mode, "Project Z");
    window.setVerticalSyncEnabled(true);

    enemies.clear();
    enemies.push_back(Enemy());
    enemies.push_back(Enemy(100, 100, 100, 100));

    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        while (auto eventOpt = window.pollEvent()) {
            const sf::Event &event = *eventOpt;
            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        player.update();

        window.clear(sf::Color::Black);
        player.draw(window);

        for (auto& e : enemies) {
            e.draw(window);
        }

        window.display();
    }
}
