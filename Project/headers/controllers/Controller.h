//
// Created by arthu on 16/05/2026.
//

#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H

#include "LoginView.h"
#include "View.h"

class PlayerContainer;
class Game;

class Controller {
private:
    View view;
    LoginView loginView;
    PlayerContainer* playerContainer;
    Game* currentGame;
    string currentNickname;

    void runLogin();
    void runNewGame();
    void runRankingType();
    void runStatistics();
    void runHelpAndRules();

public:
    Controller();
    ~Controller();
    void runMain();
};

#endif