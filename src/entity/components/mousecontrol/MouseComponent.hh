#ifndef __MOUSECOMPONENT_H__
#define __MOUSECOMPONENT_H__
#include "entity/components/Component.hh"
#include "gfx/animation/Animation.hh"
#include <array>
#include <SDL2/SDL.h>

enum Direction {
    TopLeft,        // 0
    TopRight,       // 1
    BottomLeft,     // 2
    BottomRight,    // 3
    Left,           // 4
    Right,          // 5
    Top,            // 6
    Bottom          // 7
};

class MouseComponent : public Component {
public:
    MouseComponent(std::array<Animation, 8> angles);
    MouseComponent();
    ~MouseComponent();

public:
    Direction getFacingDirection();

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;

private:
    std::array<Animation, 8> m_angles;
    Direction m_direction = TopLeft;
};
#endif // __MOUSECOMPONENT_H__