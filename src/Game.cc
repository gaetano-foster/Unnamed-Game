#include "Game.hh"
#include "io/Input.hh"
#include "gfx/AssetManager.hh"
#include "tiles/TileManager.hh"
#include "states/manager/StateManager.hh"
#include "states/game/GameState.hh"
#include "camera/Camera.hh"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

Game::Game(const char* t, int w, int h, int fps) 
    : m_maxFPS(fps)
    , m_display(w, h, t)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_display.construct(-1);
    Camera::getInstance().init(0, 0, w, h);
    AssetManager::getInstance().init(m_display.getRenderer());
    TileManager::getInstance().init();
    m_gameState = new GameState(this, new World("res/maps/test.tml"));
    StateManager::get().setState(m_gameState);
}

Game::~Game() {
    AssetManager::getInstance().cleanup();
    delete m_gameState;
}

void Game::run() {
    double delta = 0;
    double deltatime;
    double time_per_tick;
    clock_t now;
    clock_t last_time;
    clock_t timer = 0;
    float ticks = 0;
    SDL_Event e;

    time_per_tick = CLOCKS_PER_SEC / m_maxFPS;
    deltatime = 1.0f / m_maxFPS;
    last_time = clock();

    while (m_running) {
    	now = clock();
        delta += (now - last_time) / time_per_tick;
        timer += now - last_time;
        last_time = now;

        if (timer >= CLOCKS_PER_SEC) {
        	deltatime = 1.0f / ticks;
            //std::cout << "FPS: " << ticks << '\n';
            ticks = 0;
            timer = 0;
        }

        if (delta >= 1) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    stop(0);
                    break;
                }
                Input::getInstance().update(e);
            }
            update(deltatime);
            render(m_display.getRenderer());
            ticks++;
            delta--;
        }
    }
}

void Game::update(float deltaTime) {
    if (StateManager::get().getState() == nullptr)
        return;
    if (!StateManager::get().getState()->update(deltaTime)) {
        std::cout << "An error has occured whilst updating!" << std::endl;
        stop(1);
    }
}

void Game::render(SDL_Renderer *renderer) {
    if (StateManager::get().getState() == nullptr)
        return;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    // draw
    if (!StateManager::get().getState()->render(renderer)) {
        std::cout << "An error has occured whilst rendering!" << std::endl;
        stop(1);
    }
    // stop
    SDL_RenderPresent(renderer);
}

void Game::start() {
    m_running = true;
    run();
}

void Game::stop(int code) {
    m_running = false;
    m_exitCode = code;
}

int Game::getExitCode() {
    return m_exitCode;
}

World* Game::getCurrentWorld() {
    return ((GameState*)(m_gameState))->getCurrentWorld();
}
