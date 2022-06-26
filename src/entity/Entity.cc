#include "Entity.hh"
#include "components/Component.hh"
#include <iostream>

int Entity::s_count = 0;

Entity::Entity() 
    : x(0)
    , y(0) 
{ 
    s_count++;
    m_id = s_count - 1;
}

Entity::Entity(int px, int py) 
    : x(px)
    , y(py) 
{
    s_count++;
    m_id = s_count - 1;
}

Entity::~Entity() {
    for (auto& [name, component] : m_components)
        delete component;
}

Entity& Entity::addComponent(Component *component) {
    m_components.insert({ component->m_name, component });
    component->m_parent = this;
    return *this;
}

Component* Entity::getComponent(std::string name) const {
    return m_components.at(name);
}

bool Entity::hasComponent(std::string name) const {
    for (auto& [_name, component] : m_components) {
        if (_name == name) {
            return true;
        }
    }
    return false;
}

int Entity::getID() const {
    return m_id;
}

bool Entity::start() const {
    m_alive = true;
    for (auto& [name, component] : m_components) {
        if (!component->start())
            return false;
    }
    return true;
}

bool Entity::update(float deltaTime) const {
    if (m_alive) {
        for (auto& [name, component] : m_components) {
            if (!component->update(deltaTime))
                return false;
        }
    }
    return true;
}

bool Entity::render(SDL_Renderer *renderer) const {
    if (m_alive) {
        for (auto& [name, component] : m_components) {
            if (!component->render(renderer))
                return false;
        }
    } 
    else {
        for (auto& [name, component] : m_components) {
            if (!component->die(renderer))
                return false;
        }
    } 
    return true;
}

void Entity::kill() {
    m_alive = false;
}
