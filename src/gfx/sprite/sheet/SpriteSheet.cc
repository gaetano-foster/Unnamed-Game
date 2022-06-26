#include "SpriteSheet.hh"
#include <cstdio>

SpriteSheet::SpriteSheet(const char *path) {
    m_sheet = SDL_LoadBMP(path);
}

SpriteSheet::~SpriteSheet() {
    SDL_FreeSurface(m_sheet);
}

Sprite* SpriteSheet::crop(SDL_Renderer *renderer, int x, int y, int w, int h) {
    SDL_Surface *sprite = SDL_CreateRGBSurface(m_sheet->flags, w, h, m_sheet->format->BitsPerPixel, m_sheet->format->Rmask, m_sheet->format->Gmask, m_sheet->format->Bmask, m_sheet->format->Amask);
    SDL_Rect r = { x, y, w, h };
    SDL_BlitSurface(m_sheet, &r, sprite, 0);
    return new Sprite(sprite, renderer);
}

SpriteSheet::SpriteSheet() {
    
}
