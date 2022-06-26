#ifndef __TILEMANAGER_H__
#define __TILEMANAGER_H__
#include "gfx/sprite/Sprite.hh"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

struct Tile {
    Tile(Sprite *tex, std::string name, bool solid = false, int id = 0);
    ~Tile();
    bool render(SDL_Renderer *renderer, int tileLength, int x, int y);

    Sprite *tex;
    std::string name;
    bool solid;
    int id;
};

class TileManager {
public:
    TileManager(TileManager const&) = delete;
    void operator=(TileManager const&) = delete;

public:
    Tile getTile(int id);
    Tile getTile(std::string name);
    void init();

public:
    static TileManager& getInstance();

private:
    TileManager();
    ~TileManager();

private:
    void addTile(Sprite *tex, std::string name, bool solid = false);

private:
    std::vector<Tile> m_tiles;
    static int tileCount;
};
#endif // __TILEMANAGER_H__