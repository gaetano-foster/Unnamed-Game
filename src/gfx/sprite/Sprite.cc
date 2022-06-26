#include "Sprite.hh"
#include <cstdio>

Sprite::Sprite(const char *path, SDL_Renderer *renderer) {
    SDL_Surface *surface = SDL_LoadBMP(path);
    m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

Sprite::Sprite(SDL_Surface *surface, SDL_Renderer *renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(m_texture);
}

bool Sprite::render(SDL_Renderer *renderer, int x, int y, int w, int h) const {
    if (m_texture == nullptr)
        return false;
    SDL_Rect r = { x, y, w, h };
    SDL_RenderCopy(renderer, m_texture, nullptr, &r);
    return true;
}

bool Sprite::render(SDL_Renderer *renderer, SDL_Rect r) const {
    if (m_texture == nullptr)
        return false;
    SDL_RenderCopy(renderer, m_texture, nullptr, &r);
    return true;
}
