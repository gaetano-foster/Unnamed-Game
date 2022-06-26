#include "GameState.hh"
#include "Mineclone.hh"

GameState::GameState(Mineclone *game, World *world) 
    : State(game)
    , m_currentWorld(world)
{ 
    m_name = "GameState";
    if (!m_currentWorld->start())
        game->stop(1);
}

GameState::~GameState() { 
    delete m_currentWorld;
}

bool GameState::update(float deltaTime) {
    return m_currentWorld->update(deltaTime);
}

bool GameState::render(SDL_Renderer *renderer) {
    return m_currentWorld->render(renderer);
}

void GameState::setWorld(World *world) {
    delete m_currentWorld;
    m_currentWorld = world;
}

World* GameState::getCurrentWorld() {
    return m_currentWorld;
}
