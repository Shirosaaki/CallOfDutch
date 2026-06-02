#pragma once
#include <SDL3/SDL.h>

class InputManager {
public:
    static InputManager& getInstance() {
        static InputManager instance;
        return instance;
    }
    // À remplir avec la gestion du clavier/souris
private:
    InputManager() = default;
};
