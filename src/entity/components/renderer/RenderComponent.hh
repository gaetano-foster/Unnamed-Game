#ifndef __RENDERCOMPONENT_H__
#define __RENDERCOMPONENT_H__
#include "entity/components/Component.hh"
#include "gfx/sprite/Sprite.hh"

class RenderComponent : public Component {
public:
    RenderComponent(Sprite *sprite);
    ~RenderComponent();

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;

private:
    RenderComponent();

private:
    Sprite *m_sprite;
};
#endif // __RENDERCOMPONENT_H__