
#ifndef SIMPLEGRAPH_PROGRAM_HPP
#define SIMPLEGRAPH_PROGRAM_HPP

#include <SFML/Graphics.hpp>
#include "StateManager.hpp"

class Program
{
public:
                        Program();
    void                run();

private:
    // Basic sub-methods of run()
    void                processEvents();
    void                update();
    void                render();

    // Main window
    sf::RenderWindow    window;

    // The object that controls of the states of the program
    StateManager        stateManager;
};



#endif //SIMPLEGRAPH_PROGRAM_HPP
