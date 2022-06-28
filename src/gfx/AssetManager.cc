#include "AssetManager.hh"
#include "animation/Animation.hh"
#include <memory>

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}

Sprite* AssetManager::getSprite(const char *name) {
    return m_sprites[name];
}

std::array<Animation, 8> AssetManager::getPlayerAnims() {
    return m_playerAnims;
}

void AssetManager::init(SDL_Renderer *renderer, const char *epath, const char *tpath) {
    std::unique_ptr<SpriteSheet> esheet = std::make_unique<SpriteSheet>(epath);
    std::unique_ptr<SpriteSheet> tsheet = std::make_unique<SpriteSheet>(tpath);
    
    auto crop = [&renderer](SpriteSheet *s, int x, int y, int spritesize) {
        return s->crop(renderer, x*spritesize, y*spritesize, spritesize, spritesize);
    };

    // tiles
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

    // entities
    m_sprites.insert({"topleft_1", crop(esheet.get(), 0, 0, 16)});
    m_sprites.insert({"topleft_2", crop(esheet.get(), 0, 1, 16)});
    m_sprites.insert({"topright_1", crop(esheet.get(), 1, 0, 16)});
    m_sprites.insert({"topright_2", crop(esheet.get(), 1, 1, 16)});
    m_sprites.insert({"bottomleft_1", crop(esheet.get(), 2, 0, 16)});
    m_sprites.insert({"bottomleft_2", crop(esheet.get(), 2, 1, 16)});
    m_sprites.insert({"bottomright_1", crop(esheet.get(), 3, 0, 16)});
    m_sprites.insert({"bottomright_2", crop(esheet.get(), 3, 1, 16)});
    m_sprites.insert({"left_1", crop(esheet.get(), 4, 0, 16)});
    m_sprites.insert({"left_2", crop(esheet.get(), 4, 1, 16)});
    m_sprites.insert({"right_1", crop(esheet.get(), 5, 0, 16)});
    m_sprites.insert({"right_2", crop(esheet.get(), 5, 1, 16)});
    m_sprites.insert({"top_1", crop(esheet.get(), 6, 0, 16)});
    m_sprites.insert({"top_2", crop(esheet.get(), 6, 1, 16)});
    m_sprites.insert({"bottom_1", crop(esheet.get(), 7, 0, 16)});
    m_sprites.insert({"bottom_2", crop(esheet.get(), 7, 1, 16)});

    m_playerAnims = {
        Animation({ getSprite("topleft_1"), getSprite("topleft_2") }, 0.15f), 
        Animation({ getSprite("topright_1"), getSprite("topright_2") }, 0.15f), 
        Animation({ getSprite("bottomleft_1"), getSprite("bottomleft_2") }, 0.15f), 
        Animation({ getSprite("bottomright_1"), getSprite("bottomright_2") }, 0.15f), 
        Animation({ getSprite("left_1"), getSprite("left_2") }, 0.15f), 
        Animation({ getSprite("right_1"), getSprite("right_2") }, 0.15f), 
        Animation({ getSprite("top_1"), getSprite("top_2") }, 0.15f), 
        Animation({ getSprite("bottom_1"), getSprite("bottom_2") }, 0.15f),
    };
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
