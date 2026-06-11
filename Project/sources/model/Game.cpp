//
// Created by pedro on 16/05/2026.
//

#include "Game.h"
#include <iostream>
#include <ctime>

const vector<Game::ShipInfo>& Game::getFleet() {
    static const vector<ShipInfo> fleet = {
        {"Porta-Avioes",   5,},
        {"Navio-Tanque",   4,},
        {"Submarino",      3,},
        {"Fragata",        3,},
        {"Navio-Patrulha", 2,}
    };
    return fleet;
}

Game::Game(Player* p1, Player* p2, bool isVsAI, int difficulty) {
    this->player1 = p1;
    this->player2 = p2;
    this->vsComputer = isVsAI;
    this->aiDifficulty = difficulty;
    this->currentTurn = 1;
    this->gameOver = false;
    this->aiTargets.clear();
    this->aiShots = 0;
    this->aiHits = 0;
    this->attackedRow = -1;
    this->attackedCol = -1;
    this->prevAttackedRow = -1;
    this->prevAttackedCol = -1;
}

void Game::switchTurn() {
    if (this->currentTurn == 1) {
        this->currentTurn = 2;
    } else {
        this->currentTurn = 1;
    }
}

bool Game::checkGameOver() {
    if (this->board2.allShipsSunk()) {
        this->gameOver = true;
        if (this->player1 != NULL) {
            this->player1->registerGameOver(true);
        }
        if (this->player2 != NULL) {
            this->player2->registerGameOver(false);
        }
        return true;
    }

    if (this->board1.allShipsSunk()) {
        this->gameOver = true;
        if (this->player2 != NULL) {
            this->player2->registerGameOver(true);
        }
        if (this->player1 != NULL) {
            this->player1->registerGameOver(false);
        }
        return true;
    }
    return false;
}

void Game::prepareMatch() {
    this->currentTurn = 1;
    this->gameOver = false;
}

char Game::executeMove(int row, int column) {
    if (this->gameOver) {
        return false;
    }

    char result;
    if (this->currentTurn == 1) {
        result = this->board2.registerShot(row, column);
        if (this->player1 != NULL) {
            this->player1->registerShot(result == 'X');
        }
    }
    else {
        result = this->board1.registerShot(row, column);
        if (this->player2 != NULL) {
            this->player2->registerShot(result == 'X');
        }
    }

    if (result == 'O') {
        switchTurn();
    }

    checkGameOver();
    return result;
}

void Game::computerMove(int& row, int& col, bool& hit) {
    static bool seeded = false;
    if (!seeded) { srand(time(0)); seeded = true; }

    Board& target = this->board1;

    if (this->aiDifficulty == 1 || this->aiTargets.empty()) {
        do {
            row = rand() % 10;
            col = rand() % 10;
        } while (cellAlreadyAttacked(row, col));
    } else {
        bool found = false;

        while (!this->aiTargets.empty() && !found) {
            row = this->aiTargets.front().first;
            col = this->aiTargets.front().second;
            this->aiTargets.erase(this->aiTargets.begin());

            if (!cellAlreadyAttacked(row, col)) {
                found = true;
            }
        }
        if (!found) {
            do {
                row = rand() % 10;
                col = rand() % 10;
            } while (cellAlreadyAttacked(row, col));
        }
    }

    char result = this->board1.registerShot(row, col);
    hit = (result == 'X');
    this->aiShots++;

    if (hit) {
        this->aiHits++;
    }

    if (hit && this->aiDifficulty == 2) {
        addNeighbors(row, col);
        verifyDestroyedShips(row, col);
    }

    if (result == 'O') switchTurn();
    checkGameOver();
}

bool Game::cellAlreadyAttacked(int row, int col) const {
    char cell = this->board1.getCell(row, col);
    return (cell == 'X' || cell == 'O');
}

void Game::addNeighbors(int row, int col)
{
    bool directionKnown = (attackedRow != -1 && abs(row - attackedRow) + abs(col - attackedCol) == 1);

    if (directionKnown)
    {
        int dr = row - attackedRow;
        int dc = col - attackedCol;

        int r = row + dr;
        int c = col + dc;

        if (r >= 0 && r < 10 && c >= 0 && c < 10 && !cellAlreadyAttacked(r, c))
        {
            this->aiTargets.push_back({r, c});
        }
        r = attackedRow - dr;
        c = attackedCol - dc;
        if (r >= 0 && r < 10 && c >= 0 && c < 10 && !cellAlreadyAttacked(r, c))
        {
            this->aiTargets.push_back({r, c});
        }
    }
    else
    {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < 4; i++) {
            int r = row + dirs[i][0];
            int c = col + dirs[i][1];
            if (r >= 0 && r < 10 && c >= 0 && c < 10 && !cellAlreadyAttacked(r, c)) {
                this->aiTargets.push_back({r, c});
            }
        }
    }
    prevAttackedRow = attackedRow;
    prevAttackedCol = attackedCol;
    attackedRow = row;
    attackedCol = col;
}

void Game::verifyDestroyedShips(int row, int col) {
    const vector<Ship>& fleet = this->board1.getFleet();

    for (const Ship& ship : fleet) {
        if (this->board1.isCellPartOfShip(row, col, ship) && ship.isSunk()) {
            this->aiTargets.clear();
            this->attackedRow = -1;
            this->attackedCol = -1;
            this->prevAttackedRow = -1;
            this->prevAttackedCol = -1;
            break;
        }
    }
}

Board& Game::getActiveBoard() {
    if (this->currentTurn == 1) {
        return this->board1;
    }
    return this->board2;
}

Board& Game::getOpponentBoard() {
    if (this->currentTurn == 1) {
        return this->board2;
    }
    return this->board1;
}

Player* Game::getCurrentPlayer() const {
    if (this->currentTurn == 1) {
        return this->player1;
    }
    return this->player2;
}

bool Game::isGameOver() const {
    return this->gameOver;
}

int Game::getCurrentTurn() const {
    return currentTurn;
}

bool Game::isVsComputer() const {
    return vsComputer;
}

int Game::getAiDifficulty() const {
    return aiDifficulty;
}

Board& Game::getBoard1() {
    return board1;
}

Board& Game::getBoard2() {
    return board2;
}

const Board& Game::getBoard1() const {
    return board1;
}

const Board& Game::getBoard2() const {
    return board2;
}

Player* Game::getPlayer1() const {
    return player1;
}

Player* Game::getPlayer2() const {
    return player2;
}

int Game::getAiShots() const {
    return aiShots;
}
int Game::getAiHits() const {
    return aiHits;
}