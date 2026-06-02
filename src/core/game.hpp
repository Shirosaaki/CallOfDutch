#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include "engine/Window.hpp"
#include "engine/Renderer.hpp"
#include "roguelike/RunManager.hpp"
#include "roguelike/Encounter.hpp"

class Game {
public:
    Game() = default;
    ~Game();

    bool init();
    void run();

private:
    bool m_isRunning = false;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;
    RunManager m_runManager;
    Encounter m_encounter;
    void handleEvents();
    void update(float deltaTime);
    void render();
};
