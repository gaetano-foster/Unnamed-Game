#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <SDL2/SDL.h>

class Sprite {
public:
    Sprite(const char *path, SDL_Renderer *renderer);
    Sprite(SDL_Surface *surface, SDL_Renderer *renderer);
    ~Sprite();

public:
    bool render(SDL_Renderer *renderer, int x, int y, int width, int height) const;
    bool render(SDL_Renderer *renderer, SDL_Rect r) const;

private:
    Sprite();

private:
    SDL_Texture *m_texture;
};
#endif // __SPRITE_H__