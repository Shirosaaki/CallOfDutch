#pragma once
#include <string>

enum class CardSuit { Hearts, Diamonds, Clubs, Spades };

class Card {
public:
    Card(int value, CardSuit suit) : m_value(value), m_suit(suit) {}

    int getValue() const { return m_value; }
    bool isRevealed() const { return m_isKnownByPlayer; }
    void setRevealed(bool revealed) { m_isKnownByPlayer = revealed; }

private:
    int m_value; // 0 à 13 (Roi, Dame, Valet, As...)
    CardSuit m_suit;
    bool m_isKnownByPlayer = false; // La mécanique centrale du jeu
};
