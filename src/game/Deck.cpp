#include "Deck.hpp"

void Deck::generateStandard() {
    m_cards.clear();
    for (int suit = 0; suit < 4; ++suit) {
        for (int value = 1; value <= 13; ++value) {
            m_cards.emplace_back(value, static_cast<CardSuit>(suit));
        }
    }
}

Card Deck::draw() {
    if (m_cards.empty()) generateStandard();
    Card c = m_cards.back();
    m_cards.pop_back();
    return c;
}
