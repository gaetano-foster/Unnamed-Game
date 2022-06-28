#include "MouseComponent.hh"
#include "entity/components/rectangle/RectComponent.hh"
#include "entity/components/renderer/RenderComponent.hh"
#include "gfx/AssetManager.hh"
#include "io/Input.hh"
#include "camera/Camera.hh"
#include <iostream>

MouseComponent::MouseComponent(std::array<Animation, 8> angles) 
    : m_angles(angles)
{ 
    m_name = "MouseComponent";
}

MouseComponent::~MouseComponent()
{ }

Direction MouseComponent::getFacingDirection() {
    return m_direction;
}

bool MouseComponent::start() { 
    RenderComponent *r = ((RenderComponent*)m_parent->getComponent("RenderComponent"));
    return require("RectComponent") && require("RenderComponent") && r->isAnimated();
}

bool MouseComponent::update(float deltaTime) {
    RectComponent *rect = (RectComponent*)m_parent->getComponent("RectComponent");
    RenderComponent *render = ((RenderComponent*)m_parent->getComponent("RenderComponent"));
    int mx = Input::getInstance().getMouseX();
    int my = Input::getInstance().getMouseY();
    SDL_Rect me = { (int)(m_parent->x - Camera::getX()), (int)(m_parent->y - Camera::getY()), (int)rect->width, (int)rect->height };
    int pindex = m_direction;

    // Mouse is in the:
    if (mx <= me.x && my <= me.y) {                     // Top Left
        m_direction = TopLeft;
    }
    else if (mx > me.x + me.w && my <= me.y) {          // Top Right
        m_direction = TopRight;
    }
    else if (mx <= me.x && my > me.y + me.h) {          // Bottom Left
        m_direction = BottomLeft;
    }
    else if (mx > me.x + me.w && my > me.y + me.h) {     // Bottom Right
        m_direction = BottomRight;
    }
    else if (mx < me.x) {                               // Left
        m_direction = Left;
    }
    else if (mx > me.x + me.w) {                        // Right
        m_direction = Right;
    }
    else if (my < me.y) {                               // Top
        m_direction = Top;
    }
    else if (my > me.y + me.h) {                        // Bottom
        m_direction = Bottom;
    }

    if (m_direction != pindex)
        render->setAnimation(m_angles[m_direction]);

    return true;
}

bool MouseComponent::render(SDL_Renderer *renderer) {
    return true;
}

bool MouseComponent::die(SDL_Renderer *renderer) {
    return true;
}
