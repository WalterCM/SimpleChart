
#include "StateManager.hpp"

StateManager::StateManager()
{
    this->state = NULL;
}

void StateManager::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}


void StateManager::setState(ProgramState* state)
{
    if (this->state != NULL)
        this->state->destroy();
    this->state = state;
    if (this->state != NULL) {
        this->state->init();
        this->state->setStateManager(this);
    }
}

void StateManager::update()
{
    if (this->state != NULL)
        this->state->update();
}

void StateManager::draw()
{
    if (this->state != NULL)
        this->state->draw(this->window);
}

StateManager::~StateManager()
{
    this->state->destroy();
}


