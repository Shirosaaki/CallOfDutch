#pragma once
#include <SDL3/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    SDL_Window* getNativeWindow() const { return m_window; }

private:
    SDL_Window* m_window;
};
