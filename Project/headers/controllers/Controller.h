//
// Created by arthu on 16/05/2026.
//

#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H

#include "PlayerService.h"
#include "LoginView.h"
#include "View.h"
#include "Game.h"

class PlayerContainer;

class Controller {
private:
    View view;
    LoginView loginView;
    PlayerContainer* playerContainer;
    PlayerService* playerService;
    Game* currentGame;
    string currentNickname;

    void runNewGame();
    void runPlacement();
    void runRankingType();
    void runStatistics();
    void runHelpAndRules();

public:
    Controller();
    ~Controller();
    void runLogin();
    void runMain();
};

#endif