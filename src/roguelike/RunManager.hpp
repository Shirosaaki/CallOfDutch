#pragma once

class RunManager {
public:
    struct Progress {
        int victories = 0;
        int currentDeckSize = 6;
    };

    void startNewRun() { m_stats = Progress(); m_gameOver = false; } // AJOUT
    int getDeckSize() const { return m_stats.currentDeckSize; }       // AJOUT

    void onVictory() {
        m_stats.victories++;
        m_stats.currentDeckSize++;
    }

    void onDefeat() {
        m_stats.currentDeckSize--;
        if (m_stats.currentDeckSize <= 4) m_gameOver = true;
    }

private:
    Progress m_stats;
    bool m_gameOver = false;
};