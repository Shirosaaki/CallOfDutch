#pragma once
#include <SDL3/SDL.h>

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void clear();
    void present();
    SDL_Renderer* getNativeRenderer() const { return m_renderer; }

private:
    SDL_Renderer* m_renderer;
};
