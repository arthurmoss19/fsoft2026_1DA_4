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
    int currentShotsP1;
    int currentHitsP1;
    int currentShotsP2;
    int currentHitsP2;
    bool vsComputer;
    int aiDifficulty;
    int aiShots;
    int aiHits;
    bool gameOver;
    int attackedRow;
    int attackedCol;
    int prevAttackedRow;
    int prevAttackedCol;
    vector<pair<int,int>> aiTargets;
    void switchTurn();
    bool checkGameOver();

public:
    struct ShipInfo {
        string type;
        int size;
    };
    static const vector<ShipInfo>& getFleet();
    Game(Player* p1, Player* p2, bool isVsAI, int difficulty);
    ~Game() = default;
    char executeMove(int row, int column);
    void computerMove(int& row, int& col, bool& hit);
    int getCurrentTurn() const;
    bool isVsComputer() const;
    int getAiDifficulty() const;
    int getAiShots() const;
    int getAiHits() const;
    Board& getActiveBoard();
    Board& getOpponentBoard();
    Board& getBoard1();
    Board& getBoard2();
    const Board& getBoard1() const;
    const Board& getBoard2() const;
    Player* getPlayer1() const;
    Player* getPlayer2() const;
    Player* getCurrentPlayer() const;
    int getCurrentShotsP1() const;
    int getCurrentHitsP1() const;
    int getCurrentShotsP2() const;
    int getCurrentHitsP2() const;
    bool isGameOver() const;
    bool cellAlreadyAttacked(int row, int col) const;
    void addNeighbors(int row, int col);
};

#endif
