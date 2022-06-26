#ifndef __ASSETMANAGER_H__
#define __ASSETMANAGER_H__
#include "sprite/sheet/SpriteSheet.hh"
#include <string>
#include <unordered_map>

class AssetManager {
public:
    AssetManager(AssetManager const&) = delete;
    void operator=(AssetManager const&) = delete;

public:
    Sprite* getSprite(const char *name);
    void init(SDL_Renderer *renderer, const char *epath, const char *tpath);
    void cleanup();

public:
    static AssetManager& getInstance();

private:
    AssetManager();
    ~AssetManager();

private:
    std::unordered_map<const char*, Sprite*> m_sprites;
};
#endif // __ASSETMANAGER_H__