#include "Component.hh"
#include <iostream>

Component::Component() 
    : m_name("null") { }

Component::~Component() {
    
}

bool Component::require(std::string component) {
    if (!m_parent->hasComponent(component)) {
        std::cout << "[" << m_name << "] Error: Entity [" << m_parent->getID() << "] does not have required component " << component << "! " << std::endl;
        return false;
    }
    return true;
}

std::string Component::getName() {
    return m_name;
}
