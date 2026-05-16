//
// Created by arthu on 16/05/2026.
//

#include <iostream>
#include <string>
#include <list>
#include "Controller.h"
#include "Utils.h"

using namespace std;

void Controller::run() {
    int op = -1;
    do {
        op = this -> view.menuMain();
        switch(op) {
            case 1: runNewGame;
                break;
            case 2: runRanking;
                break;
            case 3: runStatistics;
                break;
            case 4: runHelpAndRules;
                break;
            default:
                break;
        }
    } while(op != 0);
}