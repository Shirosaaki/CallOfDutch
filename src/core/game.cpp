#include "game.hpp"
#include "ui/CardVisual.hpp"
#include <iostream>

Game::~Game() {
    SDL_Quit();
}

bool Game::init() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)) {
        return false;
    }

    m_window = std::make_unique<Window>("Call of Dutch", 1280, 720);
    m_renderer = std::make_unique<Renderer>(m_window->getNativeWindow());
    
    m_runManager.startNewRun();
    m_encounter.startNewMatch(m_runManager.getDeckSize());

    m_isRunning = true;
    return true;
}

void Game::run() {
    while (m_isRunning) {
        handleEvents();
        update(0.016f); // deltaTime simplifié
        render();
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }
        if (event.type == SDL_EVENT_KEY_DOWN) {
            if (event.key.key == SDLK_ESCAPE) m_isRunning = false;
            if (event.key.key == SDLK_R) {
                m_encounter.startNewMatch(m_runManager.getDeckSize());
            }
        }
    }
}

void Game::update(float deltaTime) {}

void Game::render() {
    m_renderer->clear();

    auto& hand = m_encounter.getPlayer().getHand(); // Correction du nom ici
    int xPos = 100;
    for (const auto& card : hand) {
        CardVisual::render(m_renderer->getNativeRenderer(), card, xPos, 300);
        xPos += 120;
    }

    m_renderer->present();
}
