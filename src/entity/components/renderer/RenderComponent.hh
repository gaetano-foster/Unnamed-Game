#ifndef __RENDERCOMPONENT_H__
#define __RENDERCOMPONENT_H__
#include "entity/components/Component.hh"
#include "gfx/animation/Animation.hh"
#include "gfx/sprite/Sprite.hh"

class RenderComponent : public Component {
public:
    RenderComponent(Sprite *sprite);
    RenderComponent(Animation animation);
    ~RenderComponent();

public:
    bool isAnimated();
    void setAnimation(Animation &animation);
    Animation& getAnimation();

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;

private:
    RenderComponent();

private:
    Sprite *m_sprite;
    Animation m_animation;
    bool m_animated = false;
};
#endif // __RENDERCOMPONENT_H__