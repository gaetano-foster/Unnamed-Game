#ifndef __STATEMANAGER_H__
#define __STATEMANAGER_H__
#include "states/State.hh"

class StateManager {
public:
    static StateManager& get();
    State* getState();
    void setState(State *state);

private:
    StateManager();
    ~StateManager();
    StateManager(StateManager const&) = delete;
    void operator=(StateManager const&) = delete;

private:
    State *currentState = nullptr;
};
#endif // __STATEMANAGER_H__