#ifndef __RECTCOMPONENT_H__
#define __RECTCOMPONENT_H__
#include "SDL2/SDL.h"
#include "entity/components/Component.hh"

class RectComponent : public Component {
public:
    RectComponent();
    RectComponent(float width, float height);
    ~RectComponent();

public:
    float width = 1;
    float height = 1;

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;
};
#endif // __RECTCOMPONENT_H__