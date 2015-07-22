
#ifndef SIMPLECHART_PROGRAMSTATE_HPP
#define SIMPLECHART_PROGRAMSTATE_HPP

#include <SFML/Graphics.hpp>

class StateManager;

class ProgramState
{
public:
    ProgramState() {}

    virtual void        init() = 0;
    virtual void        update() = 0;
    virtual void        draw(sf::RenderWindow *window) = 0;
    virtual void        destroy() = 0;
    void                changeState(StateManager* stateManater, ProgramState* state);
    void                setStateManager(StateManager* stateManager);

protected:
    StateManager*       stateManager;
    sf::Time            time;
    sf::Clock           clock;
};

#endif //SIMPLECHART_PROGRAMSTATE_HPP
