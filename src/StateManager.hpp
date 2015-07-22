
#ifndef SIMPLEGRAPH_STATEMANAGER_HPP
#define SIMPLEGRAPH_STATEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <bits/unique_ptr.h>
#include "ProgramState.hpp"

class StateManager
{
public:
                        StateManager();

    void                setWindow(sf::RenderWindow *window);
    void                setState(ProgramState* state);

    void                update();
    void                draw();

                        ~StateManager();

protected:
private:
    ProgramState*       state;
    sf::RenderWindow*   window;
};

#endif //SIMPLEGRAPH_STATEMANAGER_HPP
