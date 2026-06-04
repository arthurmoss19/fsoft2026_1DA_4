//
// Created by pedro on 16/05/2026.
//

#include <iostream>
#include "Game.h"

Game::Game(Player* p1, Player* p2, bool isVsAI, int difficulty) {
    this->player1 = p1;
    this->player2 = p2;
    this->vsComputer = isVsAI;
    this->aiDifficulty = difficulty;
    this->currentTurn = 1;
    this->gameOver = false;
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

bool Game::executeMove(int row, int column) {
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

    if (result == '0') {
        switchTurn();
    }

    checkGameOver();
    return true;
}

void Game::computerMove() {
    return;
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