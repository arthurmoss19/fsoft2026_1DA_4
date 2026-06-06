//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_GAME_H
#define PROJETOFSOFT_GAME_H

#include "Player.h"
#include "Board.h"
#include <vector>
#include <string>

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
    struct ShipInfo {
        string type;
        int size;
    };
    static const vector<ShipInfo>& getFleet();
    friend class GameMapper;
    Game(Player* p1, Player* p2, bool isVsAI, int difficulty);
    ~Game() = default;
    void prepareMatch();
    bool executeMove(int row, int column);
    void computerMove();
    int getCurrentTurn() const;
    bool isVsComputer() const;
    int getAiDifficulty() const;
    Board& getActiveBoard();
    Board& getOpponentBoard();
    Board& getBoard1();
    Board& getBoard2();
    const Board& getBoard1() const;
    const Board& getBoard2() const;
    Player* getPlayer1() const;
    Player* getPlayer2() const;
    Player* getCurrentPlayer() const;
    bool isGameOver() const;
};

#endif
