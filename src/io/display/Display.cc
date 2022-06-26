#include "Display.hh"
#include <cstdio>

Display::Display(int w, int h, const char *t) 
    : width(w)
    , height(h)
    , m_title(t) { }

Display::~Display() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}

void Display::construct(int index) {
    m_window = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    m_renderer = SDL_CreateRenderer(m_window, index, 0);
}

SDL_Renderer* Display::getRenderer() {
    return m_renderer;
}

const char* Display::getTitle() {
    return m_title;
}

void Display::setTitle(const char *title) {
    m_title = title;
    SDL_SetWindowTitle(m_window, title);
}