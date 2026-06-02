#include "Encounter.hpp"

Encounter::Encounter() {
}

void Encounter::startNewMatch(int deckSize) {
    m_drawPile.generateStandard();
    m_drawPile.shuffle();
    
    m_player.clearHand();
    for(int i = 0; i < deckSize; ++i) {
        Card c = m_drawPile.draw();
        // Dans le Dutch, on ne connaît que 2 cartes au début
        if (i < 2) c.setRevealed(true); 
        m_player.addCardToHand(c);
    }
}
