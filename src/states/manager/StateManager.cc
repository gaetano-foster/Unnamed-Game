#include "StateManager.hh"

StateManager& StateManager::get() {
    static StateManager me;
    return me;
}

State* StateManager::getState() {
    return currentState;
}

void StateManager::setState(State *state) {
    currentState = state;
}

StateManager::StateManager() {
    
}

StateManager::~StateManager() {
    
}
