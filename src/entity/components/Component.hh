#ifndef __COMPONENT_H__
#define __COMPONENT_H__
#include <SDL2/SDL.h>
#include <string>
#include "entity/Entity.hh"

class Component {
public:
    Component();
    virtual ~Component();

protected:
    virtual bool start() = 0;
    virtual bool update(float deltaTime) = 0;
    virtual bool render(SDL_Renderer *renderer) = 0;
    virtual bool die(SDL_Renderer *renderer) = 0;
    bool require(std::string component);
    std::string getName();

protected:
    Entity *m_parent;
    std::string m_name;
    
friend class Entity;
};
#endif // __COMPONENT_H__