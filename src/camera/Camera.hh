#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "entity/Entity.hh"
#include "math/Vector2.hh"
#include "io/display/Display.hh"
#include <SDL2/SDL.h>

class Camera {
public:
    Camera(Camera const&) = delete;
    void operator=(Camera const&) = delete;

public:
    void move(float x, float y);
    void setPosition(float x, float y);
    void init(float x, float y, int screenWidth, int screenHeight);
    SDL_Rect getScreenArea();

public:
    static Camera& getInstance();
    static float getX();
    static float getY();

public:
    union {
        struct {
            float x, y;
        };
        Vector2f position;
    };

private:
    Camera();
    ~Camera();

private:
    SDL_Rect m_screen;
};
#endif // __CAMERA_H__