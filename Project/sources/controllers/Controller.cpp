//
// Created by arthu on 16/05/2026.
//

#include <string>
#include "Controller.h"
#include "Utils.h"
#include "PlayerContainer.h"
#include "Game.h"
#include "NoDataException.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"

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

void Controller::runLogin() {
    int op = -1;
    do {
        op = this -> loginView.menuLogin();
        switch(op) {
            case 1: {
                string nick = loginView.getNickname("Nickname");
                try {
                    playerService -> getPlayer(nick);
                    currentNickname = nick;
                    runMain();
                } catch (NoDataException& e) {
                    this->view.printMessage(e.what());
                }
                break;
            }
                case 2: {
                PlayerLoginDTO dto = loginView.getNewPlayer();
                try {
                    playerService -> registerPlayer(dto);
                    currentNickname = dto.nickname;
                    view.printMessage("Perfil criado com sucesso! Bem-vindo, " + currentNickname + "!\n");
                    Utils::pressEnter();
                    runMain();
                } catch (InvalidDataException& e) {
                    this->view.printMessage(e.what());
                } catch (DuplicatedDataException& e) {
                    this->view.printMessage(e.what());
                }
            }
        }
    } while (op != 0);
}

void Controller::runMain() {
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