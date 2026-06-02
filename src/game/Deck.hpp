#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "Card.hpp"

class Deck {
public:
    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(m_cards.begin(), m_cards.end(), g);
    }

    void addCard(Card card) { m_cards.push_back(card); }
    void generateStandard(); // AJOUT
    Card draw();             // AJOUT
    
    void removeRandomCard() {
        if (!m_cards.empty()) m_cards.pop_back();
    }

private:
    std::vector<Card> m_cards;
};
