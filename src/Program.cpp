
#include <SFML/Graphics.hpp>
#include "Program.hpp"
#include "ProgramConstants.hpp"
#include "MainMenu.hpp"

// Initialize the window and the state manager, as well as giving it the first state, the main menu
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
    // Start the clock
    sf::Clock clock;
    sf::Time elapsed;
    while (window.isOpen()) {
        // Receive the elapsed time to calculate when to run the next frame
        elapsed = clock.getElapsedTime();
        // CCalculate if it's time to run the next frame
        if (elapsed.asSeconds() >= (1.0f / FPS)) {
            processEvents();
            update();
            render();

            // Restart the clock
            clock.restart();
        }
    }
}

void Program::processEvents()
{
    // Checks if the window is closed
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
    // updates the current state in the state manager
    stateManager.update();
}

void Program::render()
{
    // Draws the current state in the state manager
    window.clear(BACKGROUND_COLOR);
    stateManager.draw();
    window.display();
}
