#ifndef __INPUT_H__
#define __INPUT_H__
#include "math/Vector2.hh"
#include "stdint.h"
#include <SDL2/SDL.h>
#define SC(x)           SDL_SCANCODE_ ##x

class Input {
public:
    Input(Input const&) = delete;
    void operator=(Input const&) = delete;

public:
    bool keyHeld(int id);
    bool mouseDown(int id);
    void update(SDL_Event e);
    int getMouseX();
    int getMouseY();

public:
    static Input& getInstance();

private:
    Input();
    ~Input();

private:
    bool m_keys[282];
    int m_mouseX, m_mouseY;
    uint32_t m_buttons;
};
#endif // __INPUT_H__