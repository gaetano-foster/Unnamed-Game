#ifndef __STATE_H__
#define __STATE_H__
#include <SDL2/SDL.h>
#include <string>
class Mineclone;

class State {
public:
    State(Mineclone *game);
    virtual ~State();

public:
    std::string getName();
    Mineclone* getGame();

public:
    virtual bool update(float deltaTime) = 0;
    virtual bool render(SDL_Renderer *renderer) = 0;      

protected:
    Mineclone *m_game;
    std::string m_name;
};
#endif // __STATE_H__