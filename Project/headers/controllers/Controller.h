//
// Created by arthu on 16/05/2026.
//

#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H

#include "View.h"

class Controller {
private:
    View view;

    void runNewGame();
    void runRankingType();
    void runStatistics();
    void runHelpAndRules();

public:
    void run();
};

#endif