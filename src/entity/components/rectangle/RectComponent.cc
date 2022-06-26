#include "RectComponent.hh"

RectComponent::RectComponent()
    : width(1)
    , height(1) 
{ 
    m_name = "RectComponent";
}

RectComponent::RectComponent(float _width, float _height)
    : width(_width)
    , height(_height) 
{ 
    m_name = "RectComponent";
}

RectComponent::~RectComponent() 
{ }

bool RectComponent::start()
{ return true; }

bool RectComponent::update(float deltaTime)
{ return true; }

bool RectComponent::render(SDL_Renderer *renderer)
{ return true; }

bool RectComponent::die(SDL_Renderer *renderer)
{ return true; }