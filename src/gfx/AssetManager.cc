#include "AssetManager.hh"

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}

Sprite* AssetManager::getSprite(const char *name) {
    return m_sprites[name];
}

void AssetManager::init(SDL_Renderer *renderer, const char *epath, const char *tpath) {
    SpriteSheet *sheet = new SpriteSheet(epath);
    SpriteSheet *tsheet = new SpriteSheet(tpath);

    m_sprites.insert({ "smile", sheet->crop(renderer, 0, 0, 16, 16) });
    m_sprites.insert({ "grass", tsheet->crop(renderer, 0, 0, 32, 32) });
    m_sprites.insert({ "dirt", tsheet->crop(renderer, 32, 0, 32, 32) });
    delete sheet;
}

void AssetManager::cleanup() {
    for (auto& [name, sprite] : m_sprites) {
        delete sprite;
    }
}

AssetManager::AssetManager() {
    
}

AssetManager::~AssetManager() {
    
}
