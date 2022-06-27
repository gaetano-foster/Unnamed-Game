#include "RenderComponent.hh"
#include "entity/components/rectangle/RectComponent.hh"
#include "camera/Camera.hh"
#include "world/World.hh"
#include "states/manager/StateManager.hh"
#include <iostream>

RenderComponent::RenderComponent(Sprite *sprite)
    : m_sprite(sprite)
    , m_animated(false)
{
    m_name = "RenderComponent";
}

RenderComponent::RenderComponent(Animation animation)
    : m_animation(animation)
    , m_animated(true)
{
    m_name = "RenderComponent";
}

RenderComponent::~RenderComponent() 
{ }

bool RenderComponent::isAnimated() {
    return m_animated;
}

bool RenderComponent::start() {
    return require("RectComponent");
}

bool RenderComponent::update(float deltaTime) {
    if (m_animated)
        m_animation.update(deltaTime);
    return true;
}

bool RenderComponent::render(SDL_Renderer *renderer) {
    RectComponent *rect = (RectComponent*)m_parent->getComponent("RectComponent");
    SDL_Rect me = { (int)(m_parent->x - Camera::getX()), (int)(m_parent->y - Camera::getY()), (int)rect->width, (int)rect->height };
    SDL_Rect screen = Camera::getInstance().getScreenArea();
    World *world = StateManager::get().getState()->getGame()->getCurrentWorld();

    if (SDL_HasIntersection(&me, &screen)) {
        for (auto& entity : world->getEntities()) {
            if (&entity == m_parent)
                continue;
            else {
                if (!entity.hasComponent("RenderComponent"))
                    continue;
                else {
                    RenderComponent *orender = (RenderComponent*)(entity.getComponent("RenderComponent"));
                    RectComponent *orect = (RectComponent*)(entity.getComponent("RectComponent"));
                    SDL_Rect other = { (int)(entity.x - Camera::getX()), (int)(entity.y - Camera::getY()), (int)orect->width, (int)orect->height };

                    if (SDL_HasIntersection(&me, &other)){
                        if (m_animated) {
                            if (orender->isAnimated()) {
                                if ((me.y + me.h) > (other.y + other.h)) {
                                    return orender->m_animation.render(renderer, other.x, other.y, other.w, other.h) && m_animation.render(renderer, me.x, me.y, me.w, me.h);
                                }
                                else {
                                    return m_animation.render(renderer, me.x, me.y, me.w, me.h) && orender->m_animation.render(renderer, other.x, other.y, other.w, other.h);
                                }
                            }
                            else {
                                if ((me.y + me.h) > (other.y + other.h)) {
                                    return orender->m_sprite->render(renderer, other.x, other.y, other.w, other.h) && m_animation.render(renderer, me.x, me.y, me.w, me.h);
                                }
                                else {
                                    return m_animation.render(renderer, me.x, me.y, me.w, me.h) && orender->m_sprite->render(renderer, other.x, other.y, other.w, other.h);
                                }
                            }
                        }
                        else {
                            if (orender->isAnimated()) {
                                if ((me.y + me.h) > (other.y + other.h)) {
                                    return orender->m_animation.render(renderer, other.x, other.y, other.w, other.h) && m_sprite->render(renderer, me.x, me.y, me.w, me.h);
                                }
                                else {
                                    return m_sprite->render(renderer, me.x, me.y, me.w, me.h) && orender->m_animation.render(renderer, other.x, other.y, other.w, other.h);
                                }
                            }
                            else {
                                if ((me.y + me.h) > (other.y + other.h)) {
                                    return orender->m_sprite->render(renderer, other.x, other.y, other.w, other.h) && m_sprite->render(renderer, me.x, me.y, me.w, me.h);
                                }
                                else {
                                    return m_sprite->render(renderer, me.x, me.y, me.w, me.h) && orender->m_sprite->render(renderer, other.x, other.y, other.w, other.h);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (m_animated) {
            return m_animation.render(renderer, me.x, me.y, me.w, me.h);
        }
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