
#include "ProgramState.hpp"
#include "StateManager.hpp"

void ProgramState::changeState(StateManager *stateManager, ProgramState *state)
{
    stateManager->setState(state);
}

void ProgramState::setStateManager(StateManager *stateManager)
{
    this->stateManager = stateManager;
}
