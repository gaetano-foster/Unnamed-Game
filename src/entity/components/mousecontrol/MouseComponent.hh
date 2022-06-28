#ifndef __MOUSECOMPONENT_H__
#define __MOUSECOMPONENT_H__
#include "entity/components/Component.hh"
#include "gfx/animation/Animation.hh"
#include <array>
#include <SDL2/SDL.h>

class MouseComponent : public Component {
public:
    MouseComponent(std::array<Animation, 8> angles);
    MouseComponent();
    ~MouseComponent();

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;

private:
    std::array<Animation, 8> m_angles;
};
#endif // __MOUSECOMPONENT_H__