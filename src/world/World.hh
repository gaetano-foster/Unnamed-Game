#ifndef __WORLD_H__
#define __WORLD_H__
#include "tiles/TileManager.hh"
#include <SDL2/SDL.h>
#include <deque>
#include <string>
class Entity;

class World {
public:
    World(std::string mapPath);
    ~World();

public:
    std::string getMapName() const;
    const std::deque<Entity>& getEntities() const;
    int tileAt(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
    int getSpawnX() const;
    int getSpawnY() const;
    int getTileLength() const;
    int getTileArea() const;
    bool start();
    bool update(float deltaTime);
    bool render(SDL_Renderer *renderer);

private:
    std::deque<Entity> m_entities;
    std::string m_mapName;
    int *m_tileMap;
    int m_width = 0;
    int m_height = 0;
    int m_spawnX = 0;
    int m_spawnY = 0;
    int m_tileLength = 48;
};
#endif // __WORLD_H__