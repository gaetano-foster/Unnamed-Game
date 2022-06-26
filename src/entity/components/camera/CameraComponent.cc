#include "CameraComponent.hh"
#include "entity/Entity.hh"
#include "entity/components/rectangle/RectComponent.hh"
#include "states/manager/StateManager.hh"
#include "world/World.hh"
#include "camera/Camera.hh"

CameraComponent::CameraComponent() { 
    m_name = "CameraComponent";
}

CameraComponent::~CameraComponent()
{ }

bool CameraComponent::start() {
    return require("RectComponent");
}

bool CameraComponent::update(float deltaTime) {
    RectComponent *c = (RectComponent*)m_parent->getComponent("RectComponent");
    World* current = StateManager::get().getState()->getGame()->getCurrentWorld();

    Camera::getInstance().setPosition(m_parent->x - Camera::getInstance().getScreenArea().w / 2 + c->width / 2, m_parent->y - Camera::getInstance().getScreenArea().h / 2 + c->height / 2);

    if (Camera::getX() < 0)
        Camera::getInstance().setPosition(0, Camera::getY());

    if (Camera::getX() > current->getWidth() * current->getTileLength() - Camera::getInstance().getScreenArea().w)
        Camera::getInstance().setPosition(current->getWidth() * current->getTileLength() - Camera::getInstance().getScreenArea().w, Camera::getY());

    if (Camera::getY() < 0)
        Camera::getInstance().setPosition(Camera::getX(), 0);

    if (Camera::getY() > current->getHeight() * current->getTileLength() - Camera::getInstance().getScreenArea().h)
        Camera::getInstance().setPosition(Camera::getX(), current->getHeight() * current->getTileLength() - Camera::getInstance().getScreenArea().h);

    return true;
}

bool CameraComponent::render(SDL_Renderer *renderer) { 
    return true;
}

bool CameraComponent::die(SDL_Renderer *renderer) { 
    return true;
}
