#include "Camera.hh"

void Camera::move(float _x, float _y) {
    x += _x;
    y += _y;
}

void Camera::setPosition(float _x, float _y) {
    x = _x;
    y = _y;
}

Camera& Camera::getInstance() {
    static Camera instance;
    return instance;
}

float Camera::getX() {
    return getInstance().x;
}

float Camera::getY() {
    return getInstance().y;
}

void Camera::init(float _x, float _y, int screenWidth, int screenHeight) {
    x = _x;
    y = _y;
    m_screen = { 0, 0, screenWidth, screenHeight };
}

SDL_Rect Camera::getScreenArea() {
    return m_screen;
}

Camera::Camera()
{ }

Camera::~Camera()
{ }
