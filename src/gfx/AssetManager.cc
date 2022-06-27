#include "AssetManager.hh"
#include <memory>

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}

Sprite* AssetManager::getSprite(const char *name) {
    return m_sprites[name];
}

void AssetManager::init(SDL_Renderer *renderer, const char *epath, const char *tpath) {
    std::unique_ptr<SpriteSheet> esheet = std::make_unique<SpriteSheet>(epath);
    std::unique_ptr<SpriteSheet> tsheet = std::make_unique<SpriteSheet>(tpath);
    
    auto crop = [&renderer](SpriteSheet *s, int x, int y, int spritesize) {
        return s->crop(renderer, x*spritesize, y*spritesize, spritesize, spritesize);
    };

    m_sprites.insert({ "null",  crop(tsheet.get(), 0, 0, 16) });
    m_sprites.insert({ "smile", crop(tsheet.get(), 0, 1, 16) });
    m_sprites.insert({ "grass", crop(tsheet.get(), 1, 0, 16) });
    m_sprites.insert({ "dirt",  crop(tsheet.get(), 2, 0, 16) });
    m_sprites.insert({ "stone", crop(tsheet.get(), 3, 0, 16) });
    m_sprites.insert({ "sand",  crop(tsheet.get(), 4, 0, 16) });
    m_sprites.insert({ "grass_s", crop(tsheet.get(), 1, 1, 16) });
    m_sprites.insert({ "dirt_s",  crop(tsheet.get(), 2, 1, 16) });
    m_sprites.insert({ "stone_s", crop(tsheet.get(), 3, 1, 16) });
    m_sprites.insert({ "sand_s",  crop(tsheet.get(), 4, 1, 16) });
    m_sprites.insert({ "water", crop(tsheet.get(), 5, 0, 16) });
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
