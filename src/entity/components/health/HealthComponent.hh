#ifndef __HEALTHCOMPONENT_H__
#define __HEALTHCOMPONENT_H__
#include "../Component.hh"

class HealthComponent : public Component {
public:
    HealthComponent();
    HealthComponent(int maxHealth);
    ~HealthComponent() override;

public:
    void hurt(int amount);
    void heal(int amount, bool overheal = false);
    int getHealth();

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;

private:
    int m_maxHealth = 20;
    int m_health = 20;
};
#endif // __HEALTHCOMPONENT_H__