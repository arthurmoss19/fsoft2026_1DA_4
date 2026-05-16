//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_GAME_H
#define PROJETOFSOFT_GAME_H

#include "Player.h"
#include "Board.h"

using namespace std;

class Game {
private:
    Player* player1;
    Player* player2;
    Board board1;
    Board board2;
    int currentTurn;
    bool vsComputer;
    int aiDifficulty;
    bool gameOver;
    void switchTurn();
    bool checkGameOver();

public:
    Game(Player* p1, Player* p2, bool isVsAI, int difficulty);
    ~Game() = default;
    void prepareMatch();
    bool executeMove(int row, int column);
    void computerMove();
    Board& getActiveBoard();
    Board& getOpponentBoard();
    Player* getCurrentPlayer() const;
    bool isGameOver() const;
};

#endif
