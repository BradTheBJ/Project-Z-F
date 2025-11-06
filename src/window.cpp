#include "window.hpp"


float deltaTime = 0.f;

void game() {
    Window w;
    Player player;

    sf::RenderWindow window(
        sf::VideoMode({static_cast<unsigned int>(w.width),
                       static_cast<unsigned int>(w.height)}),
        "Project Z",
        sf::State::Windowed
    );

    window.setVerticalSyncEnabled(true);

    sf::Clock clock; // measures time per frame

    while (window.isOpen()) {
        // calculate delta time (in seconds)
        deltaTime = clock.restart().asSeconds();

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        player.update(); // will use deltaTime

        window.clear(sf::Color::Black);
        player.update();
        player.draw(window);
        window.display();
    }
}
