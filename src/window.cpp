#include "window.hpp"
#include "globals.hpp"
#include "player.hpp"
#include "enemy.hpp"

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

        while (auto eventOpt = window.pollEvent()) {
            if (eventOpt->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();

        player.update();

        for (auto& e : enemies)
            e.update(player);

        camera.setCenter(player.getPosition());
        window.setView(camera);

        window.clear(sf::Color::Black);
        player.draw(window);
        for (auto& e : enemies)
            e.draw(window);
        window.display();
    }
}
