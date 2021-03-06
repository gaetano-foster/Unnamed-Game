#ifndef __MINECLONE_H__
#define __MINECLONE_H__
#include "io/display/Display.hh"
#include "gfx/sprite/Sprite.hh"
#include "gfx/sprite/sheet/SpriteSheet.hh"
#include "states/State.hh"
#include <SDL2/SDL.h>
class World;

class Game {
public:
    Game(const char *title, int width, int height, int maxFPS);
    ~Game();

public:
    void start();
    void stop(int exitCode = 0);
    int getExitCode();
    World* getCurrentWorld();
    
private:
    void update(float deltatime);
    void render(SDL_Renderer *renderer);
    void run();

private:
    int m_maxFPS;
    int m_exitCode = 0;
    bool m_running = false;
    Display m_display;
    State *m_gameState;
};
#endif // __MINECLONE_H__