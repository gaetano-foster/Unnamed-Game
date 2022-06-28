#include "Input.hh"
#include <cstdlib>
#include <cstdio>

Input& Input::getInstance() {
    static Input me;
    return me;
}

bool Input::keyHeld(int id) {
    return m_keys[id];
}

bool Input::mouseDown(int id) {
    return m_buttons & SDL_BUTTON(id);
}

void Input::update(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
        m_keys[e.key.keysym.scancode] = true;
    }
    else if (e.type == SDL_KEYUP) {
        m_keys[e.key.keysym.scancode] = false;
    }
    m_buttons = SDL_GetMouseState(&m_mouseX, &m_mouseY);
}

int Input::getMouseX() {
    return m_mouseX;
}

int Input::getMouseY() {
    return m_mouseY;
}

Input::Input() 
{ }

Input::~Input() 
{ }
