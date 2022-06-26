#include "ControllerComponent.hh"
#include "io/Input.hh"
#include "camera/Camera.hh"
#include "entity/components/physics/PhysicsComponent.hh"
#include <algorithm>
#include <cmath>
#define SIGN(x)             ((x > 0) ? 1 : ((x < 0) ? -1 : 0))

ControllerComponent::ControllerComponent(float _topSpeed, float _accSpeed, float _decSpeed, float _friction) 
    : topSpeed(_topSpeed)
    , accSpeed(_accSpeed)
    , decSpeed(_decSpeed)
    , friction(_friction)
{
    m_name = "ControllerComponent";
}

ControllerComponent::~ControllerComponent() 
{ }

bool ControllerComponent::start() {
    return require("PhysicsComponent");
}

bool ControllerComponent::update(float deltaTime) {
    PhysicsComponent *c = (PhysicsComponent*)m_parent->getComponent("PhysicsComponent");

    if (Input::getInstance().keyHeld(SC(W))) {
        if (c->vy > 0) {
            c->vy -= decSpeed;
            if (c->vy <= 0)
                c->vy = -0.5f;
        }
        else if (c->vy > -topSpeed) {
            c->vy -= accSpeed;
            if (c->vy <= -topSpeed)
                c->vy = -topSpeed;
        }
    }
    if (Input::getInstance().keyHeld(SC(S))) {
        if (c->vy < 0) {
            c->vy += decSpeed;
            if (c->vy >= 0)
                c->vy = 0.5f;
        }
        else if (c->vy < topSpeed) {
            c->vy += accSpeed;
            if (c->vy >= topSpeed)
                c->vy = topSpeed;
        }
    }
    if (Input::getInstance().keyHeld(SC(A))) {
        if (c->vx > 0) {
            c->vx -= decSpeed;
            if (c->vx <= 0)
                c->vx = -0.5f;
        }
        else if (c->vx > -topSpeed) {
            c->vx -= accSpeed;
            if (c->vx <= -topSpeed)
                c->vx = -topSpeed;
        }
    }
    if (Input::getInstance().keyHeld(SC(D))) {
        if (c->vx < 0) {
            c->vx += decSpeed;
            if (c->vx >= 0)
                c->vx = 0.5f;
        }
        else if (c->vx < topSpeed) {
            c->vx += accSpeed;
            if (c->vx >= topSpeed)
                c->vx = topSpeed;
        }
    }

    if (!Input::getInstance().keyHeld(SC(W)) && !Input::getInstance().keyHeld(SC(S)))
        c->vy -= std::min(fabs(c->vy), friction) * SIGN(c->vy);

    if (!Input::getInstance().keyHeld(SC(A)) && !Input::getInstance().keyHeld(SC(D)))
        c->vx -= std::min(fabs(c->vx), friction) * SIGN(c->vx);
    
    return true;
}

bool ControllerComponent::render(SDL_Renderer *renderer) {
    return true;
}

bool ControllerComponent::die(SDL_Renderer *renderer) {
    return true;
}
