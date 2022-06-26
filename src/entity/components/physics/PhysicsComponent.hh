#ifndef __DYNAMICCOMPONENT_H__
#define __DYNAMICCOMPONENT_H__
#include "entity/components/Component.hh"

class PhysicsComponent : public Component {
public:
    PhysicsComponent();
    PhysicsComponent(float maxSpeed);
    ~PhysicsComponent() override;

public:
    union {
        struct {
            float vx, vy;
        };
        Vector2f velocity;
    };

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;

private:
    const float MAX_SPEED = 200.0f;
};
#endif // __DYNAMICCOMPONENT_H__