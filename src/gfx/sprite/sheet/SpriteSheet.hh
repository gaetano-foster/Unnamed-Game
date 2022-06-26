#ifndef __SPRITESHEET_H__
#define __SPRITESHEET_H__
#include "../Sprite.hh"
#include <SDL2/SDL.h>

class SpriteSheet {
public:
    SpriteSheet(const char *path);
    ~SpriteSheet();

public:
    Sprite* crop(SDL_Renderer *renderer, int x, int y, int width, int height);

private:
    SpriteSheet();

private:
    SDL_Surface *m_sheet;
};
#endif // __SPRITESHEET_H__