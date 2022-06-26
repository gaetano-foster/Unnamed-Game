#include "TileManager.hh"
#include "camera/Camera.hh"

Tile::Tile(Sprite *_tex, std::string _name, bool _solid, int _id) 
    : tex(_tex) 
    , name(_name) 
    , solid(_solid)
    , id(_id) { }

Tile::~Tile() 
{ }

bool Tile::render(SDL_Renderer *renderer, int tileLength, int x, int y) {
    SDL_Rect me = { (int)((x * tileLength) - Camera::getX()), (int)((y * tileLength) - Camera::getY()), tileLength, tileLength };
    SDL_Rect screen = Camera::getInstance().getScreenArea();
    if (tex == nullptr)
        return false;

    if (SDL_HasIntersection(&me, &screen))
        return tex->render(renderer, me.x, me.y, tileLength, tileLength);
    else
        return true;
}