#include "World.hh"

int World::getWidth() const {
    return m_width;
}

int World::getHeight() const {
    return m_height;
}

int World::getSpawnX() const {
    return m_spawnX;
}

int World::getSpawnY() const {
    return m_spawnY;
}

std::string World::getMapName() const {
    return m_mapName;
}

int World::getTileLength() const {
    return m_tileLength;
}

int World::getTileArea() const {
    return m_tileLength * m_tileLength;
}

const std::deque<Entity>& World::getEntities() const {
    return m_entities;
}