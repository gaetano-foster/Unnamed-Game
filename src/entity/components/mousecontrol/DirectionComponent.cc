#include "DirectionComponent.hh"
#include "entity/components/rectangle/RectComponent.hh"
#include "entity/components/renderer/RenderComponent.hh"
#include "gfx/AssetManager.hh"
#include "io/Input.hh"
#include "camera/Camera.hh"
#include <iostream>

DirectionComponent::DirectionComponent(std::array<Animation, 8> angles) 
    : m_angles(angles)
{ 
    m_name = "DirectionComponent";
}

DirectionComponent::~DirectionComponent()
{ }

Direction DirectionComponent::getFacingDirection() {
    return m_direction;
}

bool DirectionComponent::start() { 
    RenderComponent *r = ((RenderComponent*)m_parent->getComponent("RenderComponent"));
    return require("RectComponent") && require("RenderComponent") && r->isAnimated();
}

bool DirectionComponent::update(float deltaTime) {
    RectComponent *rect = (RectComponent*)m_parent->getComponent("RectComponent");
    RenderComponent *render = ((RenderComponent*)m_parent->getComponent("RenderComponent"));
    int mx = Input::getInstance().getMouseX();
    int my = Input::getInstance().getMouseY();
    SDL_Rect me = { (int)(m_parent->x - Camera::getX()), (int)(m_parent->y - Camera::getY()), (int)rect->width, (int)rect->height };
    int pindex = m_direction;

    // Mouse is in the:
    if (mx <= me.x && my <= me.y) {                     
        m_direction = TopLeft;
    }
    else if (mx > me.x + me.w && my <= me.y) {          
        m_direction = TopRight;
    }
    else if (mx <= me.x && my > me.y + me.h) {          
        m_direction = BottomLeft;
    }
    else if (mx > me.x + me.w && my > me.y + me.h) {    
        m_direction = BottomRight;
    }
    else if (mx < me.x) {                               
        m_direction = Left;
    }
    else if (mx > me.x + me.w) {                        
        m_direction = Right;
    }
    else if (my < me.y) {                               
        m_direction = Top;
    }
    else if (my > me.y + me.h) {                        
        m_direction = Bottom;
    }

    if (m_direction != pindex)
        render->setAnimation(m_angles[m_direction]);

    return true;
}

bool DirectionComponent::render(SDL_Renderer *renderer) {
    return true;
}

bool DirectionComponent::die(SDL_Renderer *renderer) {
    return true;
}
