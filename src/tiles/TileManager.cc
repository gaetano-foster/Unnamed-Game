#include "TileManager.hh"
#include "gfx/AssetManager.hh"
#include <vector>

int TileManager::tileCount = 0;

Tile TileManager::getTile(int id) {
    if (id < 0 || id >= tileCount) {
        return { AssetManager::getInstance().getSprite("null"), "null", false, -1 };
    }
    return m_tiles[id];
}

Tile TileManager::getTile(std::string name) {
    for (auto tile : m_tiles) {
        if (tile.name == name) {
            return tile;
        }
    }
    return { AssetManager::getInstance().getSprite("null"), "null", false, -1 };
}

void TileManager::init() {
    auto sprite = [](const char *name) { return AssetManager::getInstance().getSprite(name); };

    addTile(sprite("grass"), "grass", false);
    addTile(sprite("dirt"), "dirt", false);
    addTile(sprite("stone"), "stone", false);
    addTile(sprite("sand"), "sand", false);
    addTile(sprite("grass_s"), "grass_s", true);
    addTile(sprite("dirt_s"), "dirt_s", true);
    addTile(sprite("stone_s"), "stone_s", true);
    addTile(sprite("sand_s"), "sand_s", true);
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
