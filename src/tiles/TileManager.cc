#include "TileManager.hh"
#include "gfx/AssetManager.hh"
#include <vector>

int TileManager::tileCount = 0;

Tile TileManager::getTile(int id) {
    if (id < 0 || id >= tileCount) {
        return { nullptr, "null", false, id };
    }
    return m_tiles[id];
}

Tile TileManager::getTile(std::string name) {
    for (auto tile : m_tiles) {
        if (tile.name == name) {
            return tile;
        }
    }
    return { nullptr, name, false, -1 };
}

void TileManager::init() {
    addTile(AssetManager::getInstance().getSprite("grass"), "grass", false);
    addTile(AssetManager::getInstance().getSprite("dirt"), "dirt", true);
}

TileManager& TileManager::getInstance() {
    static TileManager instance;
    return instance;
}

TileManager::TileManager()
{ }

TileManager::~TileManager()
{ }

void TileManager::addTile(Sprite *tex, std::string name, bool solid) {
    m_tiles.emplace_back(tex, name, solid, tileCount);
    tileCount++;
}
