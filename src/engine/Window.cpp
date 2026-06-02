#include "Window.hpp"
#include <iostream>

Window::Window(const std::string& title, int width, int height) {
    m_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE);
    if (!m_window) {
        SDL_Log("Erreur création fenêtre: %s", SDL_GetError());
    }
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
}
