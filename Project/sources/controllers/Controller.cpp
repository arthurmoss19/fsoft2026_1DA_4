//
// Created by arthu on 16/05/2026.
//

#include <string>
#include "Controller.h"
#include "Utils.h"

using namespace std;

void Controller::run() {
    int op = -1;
    do {
        op = this -> view.menuMain();
        switch(op) {
            case 1: runNewGame();
                break;
            case 2: runRanking();
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

void Controller::runRanking() {
    int op = -1;
    do {
        op = this -> view.menuRanking();
        switch(op) {

        }
    } while (op != 0);
}

void Controller::runStatistics() {
    int op = -1;
    do {
        op = this -> view.menuStatiscs();
        switch(op) {

        }
    } while (op != 0);
}

void Controller::runHelpAndRules() {
    this -> view.printHelpAndRules();

    Utils::getString("Pressione ENTER para voltar ao menu");
}