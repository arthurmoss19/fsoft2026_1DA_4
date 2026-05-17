//
// Created by arthu on 16/05/2026.
//

#include <string>
#include <list>
#include "Controller.h"
#include "Utils.h"
1
#include "PlayerContainer.h"
#include "Game.h"

using namespace std;

Controller::Controller() {
    this->playerContainer = new PlayerContainer();
    this->currentGame = nullptr;
}

Controller::~Controller() {
    delete this->playerContainer;
    if (this->currentGame != nullptr) {
        delete this->currentGame;
    }
}

void Controller::run() {
    int op = -1;
    do {
        op = this -> view.menuMain();
        switch(op) {
            case 1: runNewGame();
                break;
            case 2: runRankingType();
                break;
            case 3: runStatistics();
                break;
            case 4: runHelpAndRules();
                break;
            default:
                break;
        }
    } while (op != 0);
}

void Controller::runNewGame() {
    int op = -1;
    do {
        op = this -> view.menuNewGame();
        switch(op) {

        }
    } while (op != 0);
}

void Controller::runRankingType() {
    int op = -1;
    do {
        op = this -> view.menuRankingType();
        switch(op) {

        }
    } while (op != 0);
}

void Controller::runStatistics() {
    int op = -1;
    do {
        op = this -> view.menuStatistics();
        switch(op) {

        }
    } while (op != 0);
}

void Controller::runHelpAndRules() {
    this -> view.printHelpAndRules();
    Utils::pressEnter();
}