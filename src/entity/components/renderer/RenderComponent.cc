#include "RenderComponent.hh"
#include "entity/components/rectangle/RectComponent.hh"
#include "camera/Camera.hh"
#include <iostream>

RenderComponent::RenderComponent() 
    : m_sprite(nullptr) 
{ 
    m_name = "RenderComponent";
}

RenderComponent::RenderComponent(Sprite *sprite)
    : m_sprite(sprite)
{
    m_name = "RenderComponent";
}

RenderComponent::~RenderComponent() 
{ }

bool RenderComponent::start() {
    return require("RectComponent") && m_sprite != nullptr;
}

bool RenderComponent::update(float deltaTime) {
    return true;
}

bool RenderComponent::render(SDL_Renderer *renderer) {
    RectComponent *c = (RectComponent*)m_parent->getComponent("RectComponent");
    SDL_Rect me = { (int)(m_parent->x - Camera::getX()), (int)(m_parent->y - Camera::getY()), (int)c->width, (int)c->height };
    SDL_Rect screen = Camera::getInstance().getScreenArea();
    if (m_sprite == nullptr) {
        std::cout << "Error: Sprite of RenderComponent of Entity #" << m_parent->getID() << " is null!" << std::endl;
        return false;
    }
    if (SDL_HasIntersection(&me, &screen)) {
        return m_sprite->render(renderer, me.x, me.y, me.w, me.h); 
    }
    else {
        return true;
    }
}

bool RenderComponent::die(SDL_Renderer *renderer) {
    // TODO: Implement optional death animation
    return true;
}