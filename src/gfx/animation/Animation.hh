#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include "gfx/sprite/Sprite.hh"
#include <vector>

class Animation {
public:
    Animation(std::vector<Sprite*> frames, float delay);
    Animation();
    ~Animation();

public:
    bool update(float deltaTime);
    bool render(SDL_Renderer *renderer, int x, int y, int width, int height);

private:
    std::vector<Sprite*> m_frames;
    int m_index = 0;
    float m_delay = 1.0f;
    float m_shouldSwitch = 0.0f;
};
#endif // __ANIMATION_H__