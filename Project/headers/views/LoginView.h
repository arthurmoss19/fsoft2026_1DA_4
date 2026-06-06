//
// Created by arthu on 17/05/2026.
//

#ifndef PROJECT_LOGINVIEW_H
#define PROJECT_LOGINVIEW_H

#include "PlayerLoginDTO.h"

using namespace std;

class LoginView {
public:
    PlayerLoginDTO getNewPlayer();
    string getNickname(const string& label);
    int menuLogin(const string& title = "********** Batalha Naval **********");
};

#endif //PROJECT_LOGINVIEW_H