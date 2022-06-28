#include "PhysicsComponent.hh"

PhysicsComponent::PhysicsComponent()
    : velocity({ 0, 0 })
    , MAX_SPEED(800) 
{
    m_name = "PhysicsComponent";
}

PhysicsComponent::PhysicsComponent(float maxSpeed)
    : velocity({ 0, 0 })
    , MAX_SPEED(maxSpeed) 
{ 
    m_name = "PhysicsComponent";
}


PhysicsComponent::~PhysicsComponent()
{ }

bool PhysicsComponent::start() {
    return true;
}

bool PhysicsComponent::update(float deltaTime) {
    if (MAX_SPEED <= 0) goto end;
    if (vx > MAX_SPEED) vx = MAX_SPEED;
    if (vy > MAX_SPEED) vy = MAX_SPEED;
    if (vx < -MAX_SPEED) vx = -MAX_SPEED;
    if (vy < -MAX_SPEED) vy = -MAX_SPEED;
end:
    if (!m_parent->hasComponent("ColliderComponent"))
        m_parent->position += velocity * deltaTime;
    return true;
}

bool PhysicsComponent::render(SDL_Renderer *renderer) {
    return true;
}

bool PhysicsComponent::die(SDL_Renderer *renderer) {
    return true;
}
