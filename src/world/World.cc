#include "World.hh"
#include "strings/StringManipulation.hh"
#include "states/manager/StateManager.hh"
#include "gfx/AssetManager.hh"
#include "entity/Entity.hh"
#include "entity/components/controller/ControllerComponent.hh"
#include "entity/components/health/HealthComponent.hh"
#include "entity/components/physics/PhysicsComponent.hh"
#include "entity/components/rectangle/RectComponent.hh"
#include "entity/components/renderer/RenderComponent.hh"
#include "entity/components/camera/CameraComponent.hh"
#include "entity/components/collider/ColliderComponent.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include <strstream>
#include <algorithm>
#define LOG(x)      std::cout << x << std::endl

World::World(std::string mapPath) {
    std::ifstream f(mapPath.c_str());
	if (!f.is_open()) {
        m_tileMap = nullptr;
        std::cout << "Error! Failed to load file at " << mapPath << '\n'; 
		return;
    }

    int i = 0;
	while (!f.eof()) {
		char line[256];
		f.getline(line, 256);

		std::strstream s;
		s << line;
        std::vector<std::string> tokens = str_split(line, " ");

        if (i == 0) {
            m_mapName = std::string(line);
        }
        if (i == 1) {
            m_width = std::stoi(tokens[0]);
            m_height = std::stoi(tokens[1]);
            m_tileMap = new int[m_width*m_height];
        }
        else if (i == 2) {
            m_spawnX = std::stoi(tokens[0]);
            m_spawnY = std::stoi(tokens[1]);
        }
        else if (i == 3) {
            m_tileLength = std::stoi(tokens[0]);
        }
        else {
            int y = i - 4;
            for (int x = 0; x < m_width; x++) {
                m_tileMap[y*m_width+x] = std::stoi(tokens[x]);
            }
        }

        i++;
	}

    // initialize player
    m_entities.emplace_back(m_spawnX * m_tileLength, m_spawnY * m_tileLength)
    .addComponent(new PhysicsComponent())
    .addComponent(new RectComponent(48, 48))
    .addComponent(new HealthComponent(20))
    .addComponent(new RenderComponent(AssetManager::getInstance().getSprite("smile")))
    .addComponent(new ControllerComponent(360, 5, 10, 10))
    .addComponent(new CameraComponent())
    .addComponent(new ColliderComponent(0, 24, 48, 24, false));

    // TODO: initialize other entities
    m_entities.emplace_back(10 * m_tileLength, 10 * m_tileLength)
    .addComponent(new PhysicsComponent())
    .addComponent(new RectComponent(48, 48))
    .addComponent(new RenderComponent(AssetManager::getInstance().getSprite("smile")))
    .addComponent(new ColliderComponent());

    for (auto& entity : m_entities) {
        if (!entity.start())
            StateManager::get().getState()->getGame()->stop(1);
    }
}

World::~World() {
    if (m_tileMap != nullptr)
        delete[] m_tileMap;
}

int World::tileAt(int x, int y) const {
    return m_tileMap[y*m_width+x];
}

bool World::start() {
    if (m_tileMap == nullptr)
        return false;
    
    for (auto& entity : m_entities) {
        if (!entity.start())
            return false;
    }
    return true;
}

bool World::update(float deltaTime) {
    PhysicsComponent *phys = (PhysicsComponent*)(m_entities[1].getComponent("PhysicsComponent"));
    phys->vx = 10;
    for (auto& entity : m_entities) {
        if (!entity.update(deltaTime))
            return false;
    }
    return true;
}

bool World::render(SDL_Renderer *renderer) {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            if (TileManager::getInstance().getTile(m_tileMap[y*m_width+x]).name == "null") {
                std::cout << "Error with map [" << m_mapName << "]: Tile #" << TileManager::getInstance().getTile(m_tileMap[y*m_width+x]).id << " does not exist!";
                return false;
            }
            else {
                if (!TileManager::getInstance().getTile(m_tileMap[y*m_width+x]).render(renderer, m_tileLength, x, y))
                    return false;
            }
        }
    }

    auto sortfunc = [](Entity &e1, Entity &e2) {
        if (e1.hasComponent("RectComponent")) {
            RectComponent *r1 = (RectComponent*)(e1.getComponent("RectComponent"));
            if (e2.hasComponent("RectComponent")) {
                RectComponent *r2 = (RectComponent*)(e2.getComponent("RectComponent"));
                return (e1.y + r1->height) < (e2.y + r2->height);
            }
            else {
                return (e1.y + r1->height) < (e2.y);
            }
        }
        else {
            if (e2.hasComponent("RectComponent")) {
                RectComponent *r2 = (RectComponent*)(e2.getComponent("RectComponent"));
                return (e1.y) < (e2.y + r2->height);
            }
        }
        return e1.y < e2.y;
    };

    std::sort(m_entities.begin(), m_entities.end(), sortfunc);

    for (auto& entity : m_entities) {
        if (!entity.render(renderer)) {
            return false;
        }
    }
    return true;
}
