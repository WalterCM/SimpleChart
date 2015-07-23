
#include <SFML/Graphics.hpp>
#include "Program.hpp"
#include "ProgramConstants.hpp"
#include "MainMenu.hpp"
typedef unsigned int uint;
Program::Program()
        : window(sf::VideoMode((uint)WINDOW_WIDTH, (uint)WINDOW_HEIGHT),
                 TITLE_STRING)
        , stateManager()
{
    stateManager.setWindow(&window);
    stateManager.setState(new MainMenu());
}

void Program::run()
{
    sf::Clock clock;
    sf::Time elapsed;
    while (window.isOpen()) {
        elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() >= (1.0f / FPS)) {
            processEvents();
            update();
            render();

            clock.restart();
        }
    }
}

void Program::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                exit(0);
            default:
                break;
        }
    }
}

void Program::update()
{
    stateManager.update();
}

void Program::render()
{
    window.clear(BACKGROUND_COLOR);
    stateManager.draw();
    window.display();
}
