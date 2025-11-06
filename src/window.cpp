#include "window.hpp"


void game() {
    Window w;
    Player player;
    Enemy enemy;

    sf::RenderWindow window(
        sf::VideoMode({static_cast<unsigned int>(w.width),
                       static_cast<unsigned int>(w.height)}),
        "Project Z",
        sf::State::Windowed
    );

    window.setVerticalSyncEnabled(true);

    enemies.push_back(Enemy());  // Uses default (300, 300, 100, 100)
    enemies.push_back(Enemy(100, 100, 100, 100)); //Place holder enemy


    sf::Clock clock; // measures time per frame

    while (window.isOpen()) {
        // calculate delta time (in seconds)
        deltaTime = clock.restart().asSeconds();

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        player.update(); // will use deltaTime

        window.clear(sf::Color::Black);

        player.update();
        player.draw(window);

        for (size_t i = 0; i < enemies.size(); i++) {
        enemies[i].draw(window);
        }


        window.display();
    }
}
