#pragma once
#include <string>
#include <vector>
#include "Card.hpp"

class Player {
public:
    Player(const std::string& name = "Player") : m_name(name) {}
    
    void addCardToHand(Card card) { m_hand.push_back(card); }
    void clearHand() { m_hand.clear(); }
    std::vector<Card>& getHand() { return m_hand; }

private:
    std::string m_name;
    std::vector<Card> m_hand; // AJOUT
};