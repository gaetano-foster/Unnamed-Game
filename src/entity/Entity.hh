#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "math/Vector2.hh"
#include "Mineclone.hh"
#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
class Component;

class Entity {
public:
    Entity();
    Entity(int x, int y);
    ~Entity();

public:
    Entity& addComponent(Component *component);
    Component* getComponent(std::string name) const;
    bool hasComponent(std::string name) const;
    int getID() const;
    bool start() const;
    bool update(float deltaTime) const;
    bool render(SDL_Renderer *renderer) const;
    void kill();

public:
    union {
        struct {
            float x, y;
        };
        Vector2f position;
    };

    static int s_count;

private:
    std::unordered_map<std::string, Component*> m_components;
    mutable bool m_alive = true;
    int m_id = 0;
};
#endif // __ENTITY_H__