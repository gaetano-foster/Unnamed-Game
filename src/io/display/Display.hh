#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <SDL2/SDL.h>

class Display {
public:
    Display(int width, int height, const char *title);
    ~Display();

public:
    void construct(int driverIndex);
    SDL_Renderer* getRenderer();
    const char* getTitle();
    void setTitle(const char *title);

public:
    int width, height;

private:
    const char *m_title;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
};
#endif // __DISPLAY_H__