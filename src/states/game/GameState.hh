#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__
#include "states/State.hh"
#include "entity/Entity.hh"
#include "world/World.hh"
class Mineclone;

class GameState : public State {
public:
    GameState(Mineclone *game, World *world);
    ~GameState();

public:
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    void setWorld(World *world);
    bool loadWorld(std::string name);
    World* getCurrentWorld();

private:
    World *m_currentWorld;
};
#endif // __GAMESTATE_H__