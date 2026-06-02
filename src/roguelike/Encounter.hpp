#pragma once
#include "../game/Player.hpp"
#include "../game/Deck.hpp"

class Encounter {
public:
    Encounter();
    void startNewMatch(int deckSize);
    Player& getPlayer() { return m_player; }

private:
    Player m_player;
    Deck m_drawPile;
};
