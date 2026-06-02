#pragma once

enum class GameState { Menu, Combat, Reward, GameOver };

class StateManager {
public:
    StateManager() : m_currentState(GameState::Menu) {}
    void changeState(GameState newState) { m_currentState = newState; }
    GameState getState() const { return m_currentState; }

private:
    GameState m_currentState;
};
