
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
    void                processEvents();
    void                update();
    void                render();

    sf::RenderWindow    window;    // Main window for the GUI

    StateManager        stateManager;
};



#endif //SIMPLEGRAPH_PROGRAM_HPP
