#ifndef __CONTROLLERCOMPONENT_H__
#define __CONTROLLERCOMPONENT_H__
#include "entity/components/Component.hh"

class ControllerComponent : public Component {
public:
    ControllerComponent(float topSpeed = 15.5f, float accSpeed = 2.5f, float decSpeed = 2.5f, float friction = 1.5f);
    ~ControllerComponent() override;

public:
    float topSpeed = 15.5f;
    float accSpeed = 2.5f;
    float decSpeed = 2.5f;
    float friction = 1.5f;

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;
};
#endif // __CONTROLLERCOMPONENT_H__