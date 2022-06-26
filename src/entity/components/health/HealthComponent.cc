#include "HealthComponent.hh"
#include <algorithm>

HealthComponent::HealthComponent() 
    : m_maxHealth(20)
    , m_health(20) 
{
    m_name = "HealthComponent";
}

HealthComponent::HealthComponent(int maxHealth) 
    : m_maxHealth(maxHealth)
    , m_health(maxHealth) 
{
    m_name = "HealthComponent";
}

HealthComponent::~HealthComponent() {
    
}

void HealthComponent::hurt(int amount) {
    m_health -= amount;
}

void HealthComponent::heal(int amount, bool overheal) {
    if (overheal)
        m_health += amount;
    else 
        m_health = std::clamp(m_health + amount, 0, m_maxHealth);
}

int HealthComponent::getHealth() {
    return m_health;
}

bool HealthComponent::start() {
    return true;
}

bool HealthComponent::update(float deltaTime) {
    static float overhealTimer = 0;

    if (m_health < 0) {
        m_parent->kill();
    }

    if (m_health > m_maxHealth) {
        overhealTimer += 0.5f * deltaTime;
        if (overhealTimer >= 0.5f) {
            overhealTimer = 0;
            m_health--;
        }
    }
    
    return true;
}

bool HealthComponent::render(SDL_Renderer *renderer) {
    return true;
}

bool HealthComponent::die(SDL_Renderer *renderer) {
    return true;
}
