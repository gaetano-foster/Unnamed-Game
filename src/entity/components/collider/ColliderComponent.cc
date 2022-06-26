#include "ColliderComponent.hh"
#include "entity/components/rectangle/RectComponent.hh"
#include "entity/components/physics/PhysicsComponent.hh"
#include "states/manager/StateManager.hh"
#include "tiles/TileManager.hh"
#include "world/World.hh"
#include <SDL2/SDL.h>
#include <string>
#define TILEAT(x, y)        (TileManager::getInstance().getTile(world->tileAt((int)((x)/world->getTileLength()), (int)((y)/world->getTileLength()))))

ColliderComponent::ColliderComponent(int x, int y, int width, int height, bool useRectComponent) 
    : m_useRectComponent(useRectComponent)
    , m_collider((SDL_Rect) { x, y, width, height })
{
    m_name = "ColliderComponent";
}

ColliderComponent::~ColliderComponent() 
{ }

bool ColliderComponent::start() {
    if (m_useRectComponent) {
        if (m_parent->hasComponent("RectComponent")) {
            RectComponent *rect = (RectComponent*)(m_parent->getComponent("RectComponent"));
            m_collider = { 0, 0, (int)rect->width, (int)rect->height };
        }
        return require("RectComponent") && require("PhysicsComponent");
    }
    return require("PhysicsComponent");
}

bool ColliderComponent::update(float deltaTime) {
    PhysicsComponent *phys = (PhysicsComponent*)m_parent->getComponent("PhysicsComponent");
    World *world = StateManager::get().getState()->getGame()->getCurrentWorld();
    SDL_Rect me = { (int)(m_collider.x + m_parent->x), (int)(m_collider.y + m_parent->y), m_collider.w, m_collider.h };
    
    if ((TILEAT(me.x + phys->vx * deltaTime, me.y).solid || TILEAT((me.x + me.w) + phys->vx * deltaTime, me.y).solid))
        phys->vx = 0;

    if ((TILEAT(me.x + phys->vx * deltaTime, me.y + me.h-1).solid || TILEAT((me.x + me.w) + phys->vx * deltaTime, me.y + me.h-1).solid))
        phys->vx = 0;

    if ((TILEAT(me.x, me.y + phys->vy * deltaTime).solid || TILEAT(me.x, (me.y + me.h) + phys->vy * deltaTime).solid))
        phys->vy = 0;

    if ((TILEAT(me.x + me.w-1, me.y + phys->vy * deltaTime).solid || TILEAT(me.x + me.w-1, (me.y + me.h) + phys->vy * deltaTime).solid))
        phys->vy = 0;

    for (auto& entity : world->getEntities()) {
        if (&entity == m_parent)
            continue;
        else {
            if (!entity.hasComponent("ColliderComponent"))
                continue;
            else {
                ColliderComponent *ocollider = (ColliderComponent*)(entity.getComponent("ColliderComponent"));
                SDL_Rect other = { (int)(ocollider->m_collider.x + entity.x), (int)(ocollider->m_collider.y + entity.y), (int)(ocollider->m_collider.w), (int)(ocollider->m_collider.h) };
                SDL_Rect mex = { (int)(me.x + phys->vx * deltaTime), (int)(me.y), (int)(me.w+1), (int)(me.h-1) };
                SDL_Rect mey = { (int)(me.x), (int)(me.y + phys->vy * deltaTime), (int)(me.w-1), (int)(me.h+1) };

                if (SDL_HasIntersection(&mex, &other))
                    phys->vx = 0;

                if (SDL_HasIntersection(&mey, &other))
                    phys->vy = 0;
            }
        }
    }

    m_parent->position += phys->velocity * deltaTime;
    return true;
}

bool ColliderComponent::render(SDL_Renderer *renderer) {
    return true;
}

bool ColliderComponent::die(SDL_Renderer *renderer) {
    return true;
}
