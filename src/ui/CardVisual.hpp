#pragma once
#include <SDL3/SDL.h>
#include "../game/Card.hpp"

class CardVisual {
public:
    static void render(SDL_Renderer* renderer, const Card& card, int x, int y) {
        SDL_FRect rect = { (float)x, (float)y, 100.0f, 150.0f };
        
        // Couleur de fond de la carte
        if (card.isRevealed()) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanc si révélée
        } else {
            SDL_SetRenderDrawColor(renderer, 50, 50, 150, 255);   // Bleu si face cachée
        }
        
        SDL_RenderFillRect(renderer, &rect);
        
        // Bordure
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderRect(renderer, &rect);
    }
};
 