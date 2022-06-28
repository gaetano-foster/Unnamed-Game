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
    static int index = 0;
    int pindex = index;

    // Mouse is in the:
    if (mx <= me.x && my <= me.y) {                     // Top Left
        index = 0;
    }
    else if (mx > me.x + me.w && my <= me.y) {          // Top Right
        index = 1;
    }
    else if (mx <= me.x && my > me.y + me.h) {          // Bottom Left
        index = 2;
    }
    else if (mx > me.x + me.w && my > me.y + me.h) {     // Bottom Right
        index = 3;
    }
    else if (mx < me.x) {                               // Left
        index = 4;
    }
    else if (mx > me.x + me.w) {                        // Right
        index = 5;
    }
    else if (my < me.y) {                               // Top
        index = 6;
    }
    else if (my > me.y + me.h) {                        // Bottom
        index = 7;
    }

    if (index != pindex)
        render->setAnimation(m_angles[index]);

    return true;
}

bool MouseComponent::render(SDL_Renderer *renderer) {
    return true;
}

bool MouseComponent::die(SDL_Renderer *renderer) {
    return true;
}
