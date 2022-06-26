#ifndef __CAMERACOMPONENT_H__
#define __CAMERACOMPONENT_H__
#include "entity/components/Component.hh"

class CameraComponent : public Component {
public:
    CameraComponent();
    ~CameraComponent() override;

protected:
    bool start() override;
    bool update(float deltaTime) override;
    bool render(SDL_Renderer *renderer) override;
    bool die(SDL_Renderer *renderer) override;
};
#endif // __CAMERACOMPONENT_H__