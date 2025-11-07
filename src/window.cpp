#include "window.hpp"

void game() {
    Window w;
    Player player;

    sf::VideoMode mode({ static_cast<unsigned int>(w.width),
                         static_cast<unsigned int>(w.height) });
    sf::RenderWindow window(mode, "Project Z");

    window.setVerticalSyncEnabled(true);

    // Fix: use sf::Vector2f
    camera.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),
                                static_cast<float>(window.getSize().y)));

    // Initially center camera on player
    camera.setCenter(player.getPosition());

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

        // Update camera to follow player
        camera.setCenter(player.getPosition());
        window.setView(camera);

        window.clear(sf::Color::Black);
        player.draw(window);

        for (auto& e : enemies) {
            e.draw(window);
        }

        window.display();
    }
}
