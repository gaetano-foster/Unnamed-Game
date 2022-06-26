#ifndef __COLLIDERCOMPONENT_H__
#define __COLLIDERCOMPONENT_H__
#include "entity/components/Component.hh"

class ColliderComponent : public Component {
public:
    ColliderComponent(int x = 0, int y = 0, int width = 0, int height = 0, bool useRectComponent = true);
    ~ColliderComponent() override;

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;

private:
    bool m_useRectComponent = true;
    SDL_Rect m_collider;
};
#endif // __COLLIDERCOMPONENT_H__