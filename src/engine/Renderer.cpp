#include "Renderer.hpp"

Renderer::Renderer(SDL_Window* window) {
    m_renderer = SDL_CreateRenderer(window, nullptr); // nullptr = auto-detect driver
    if (!m_renderer) {
        SDL_Log("Erreur création rendu: %s", SDL_GetError());
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}

void Renderer::clear() {
    // Un beau bleu-vert sombre pour le tapis de jeu
    SDL_SetRenderDrawColor(m_renderer, 20, 80, 40, 255); 
    SDL_RenderClear(m_renderer);
}

void Renderer::present() {
    SDL_RenderPresent(m_renderer);
}
