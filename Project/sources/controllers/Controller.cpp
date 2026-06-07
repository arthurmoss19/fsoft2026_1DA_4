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
    this -> playerContainer = new PlayerContainer();
    this -> playerService = new PlayerService(this -> playerContainer);
    this->currentGame = nullptr;
}

Controller::~Controller() {
    delete this -> playerContainer;
    delete this->playerService;
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
                    runMain();
                } catch (InvalidDataException& e) {
                    this->view.printMessage(e.what());
                } catch (DuplicatedDataException& e) {
                    this->view.printMessage(e.what());
                }
                break;
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
        op = this->view.menuNewGame();
        switch (op) {
            case 1: this->view.menuDifficulty();
                break;
            case 2: {
                string nick2;
                bool player2nick = false;
                int op2 = -1;
                do {
                    op2 = this->loginView.menuLogin("********** Login do Jogador 2 **********");
                    switch (op2) {
                        case 1: {
                            nick2 = loginView.getNickname("Nickname do jogador 2");
                            try {
                                this->playerService->getPlayer(nick2);
                                player2nick = true;
                            } catch (NoDataException &e) {
                                this->view.printMessage(e.what());
                            }
                            break;
                        }
                        case 2: {
                            PlayerLoginDTO dto = this->loginView.getNewPlayer();
                            try {
                                this->playerService->registerPlayer(dto);
                                nick2 = dto.nickname;
                                this->view.printMessage("Perfil criado com sucesso! Bem-vindo, " + nick2 + "!\n");
                                player2nick = true;
                            } catch (InvalidDataException &e) {
                                this->view.printMessage(e.what());
                            } catch (DuplicatedDataException &e) {
                                this->view.printMessage(e.what());
                            }
                            break;
                        }
                        case 0: player2nick = true;
                    }
                } while (!player2nick && op2 != 0);

                if (player2nick && op2 != 0) {
                    Player* p1 = this->playerContainer->get(this->currentNickname);
                    Player* p2 = this->playerContainer->get(nick2);
                    this->currentGame = new Game(p1, p2, false, 0);

                    this->view.printMessage("\n********** Jogador 1: " + p1->getNickname() + " - posiciona os teus navios **********");

                    if (!runPlacement(this->currentGame->getBoard1())) {
                        delete this->currentGame;
                        this->currentGame = nullptr;
                        return;
                    }

                    Utils::pressEnterPlayerSwitch(nick2);

                    this->view.printMessage("\n********** Jogador 2: " + p2->getNickname() + " - posiciona os teus navios **********");

                    if (!runPlacement(this->currentGame->getBoard2())) {
                        delete this->currentGame;
                        this->currentGame = nullptr;
                        return;
                    }

                    Utils::pressEnter();
                    Utils::pressEnterConfirmPlayer(currentNickname);

                    this->view.printMessage("\nPreparacao concluida! O jogo vai comecar...");

                    runGameLoop();
                }
                break;
            }
        }
    } while (op != 0);
}

void Controller::runRankingType() {
    int op = -1;
    do {
        op = this->view.menuRankingType();
        switch (op) {
            case 1: {
                list<PlayerDTO> ranking = this->playerService->getRankingByWins();
                this->view.printMessage("\n********** Ranking por Numero de Vitorias **********");
                int pos = 1;
                for (const PlayerDTO &p: ranking) {
                    this->view.printMessage(to_string(pos) + ". " + p.nickname + " - " + to_string(p.victories) + " vitorias");
                    pos++;
                }
                break;
            }
            case 2: {
                list<PlayerDTO> ranking = this->playerService->getRankingByAccuracy();
                this->view.printMessage("\n********** Ranking por Taxa de Precisao **********");
                int pos = 1;
                for (const PlayerDTO &p: ranking) {
                    this->view.printMessage(to_string(pos) + ". " + p.nickname + " - " + to_string(p.accuracy) + "%");
                    pos++;
                }
                break;
            }
        }
    }while (op != 0);
}

void Controller::runStatistics() {
    int op = -1;
    do {
        op = this -> view.menuStatistics();
        switch(op) {
            case 1: {
                try {
                    PlayerDTO myStats = this->playerService->getPlayer(this->currentNickname);
                    this->view.printMessage("Nickname: " + myStats.nickname);
                    this->view.printMessage("Vitorias: " + to_string(myStats.victories));
                    this->view.printMessage("Derrotas: " + to_string(myStats.defeats));
                    this->view.printMessage("Numero de tiros dados: " + to_string(myStats.totalShots));
                    this->view.printMessage("Acertos: " + to_string(myStats.shotsHit));
                    this->view.printMessage("Precisao: " + to_string(myStats.accuracy) + "%");
                } catch (NoDataException& e) {
                    this->view.printMessage(e.what());
                }
            }
            break;
                case 2: {
                    string nick = this -> loginView.getNickname("Introduza o nickname de um jogador");
                    try {
                        PlayerDTO stats = this->playerService->getPlayer(nick);
                        this->view.printMessage("Nickname: " + stats.nickname);
                        this->view.printMessage("Vitorias: " + to_string(stats.victories));
                        this->view.printMessage("Derrotas: " + to_string(stats.defeats));
                        this->view.printMessage("Numero de tiros dados: " + to_string(stats.totalShots));
                        this->view.printMessage("Acertos: " + to_string(stats.shotsHit));
                        this->view.printMessage("Precisao: " + to_string(stats.accuracy) + "%");
                    } catch (NoDataException & e) {
                        this -> view.printMessage(e.what());
                    }
                }
                break;
        }
    } while (op != 0);
}

void Controller::runHelpAndRules() {
    this->view.printHelpAndRules();
    Utils::pressEnterMainMenu();
}

void Controller::placeFleetManually(Board& board) {
    this->view.showBoard(board, false);
    const auto& fleet = Game::getFleet();
    for (const auto& ship : fleet) {
        bool placed = false;
        while (!placed) {
            int row, col;
            bool horizontal;
            this->view.ShipPlacement(ship.type, ship.size, row, col, horizontal);

            if (!board.isWithinBounds(row, col, ship.size, horizontal)) {
                this->view.showOutOfBoundsError();
                this->view.showBoard(board, false);
                continue;
            }

            Ship newShip(ship.type, ship.size, '#');
            placed = board.placeShip(newShip, row, col, horizontal);
            if (!placed) {
                this->view.showOverlapError();
                this->view.showBoard(board, false);
            }
        }
        this->view.showBoard(board, false);
    }
}

bool Controller::runPlacement(Board& board) {
    if (this->currentGame == nullptr) return false;

    int modo = this->view.menuShipPlacement();
    if (modo == 0) return false;

    const auto& fleet = Game::getFleet();
    bool ready = false;

    while (!ready) {
        board = Board();

        if (modo == 1) {
            this->placeFleetManually(board);
        } else {
            for (const auto& ship : fleet) {
                board.placeShipAutomatically(ship.size, ship.type, '#');
            }
        }

        this->view.showBoard(board, false);
        int opt = this->view.menuSatisfaction();
        switch (opt) {
        case 1: ready = true; break;
        case 2: modo = 2; break;
        case 3: modo = 1; break;
        case 0: return false;
        }
    }

    this->view.showPlacementSuccess();
    return true;
}

void Controller::runGameLoop()
{
    if (this->currentGame == nullptr) return;

    while (!this->currentGame->isGameOver()) {
        string player = this->currentGame->getCurrentPlayer()->getNickname();
        Board& myBoard = this->currentGame->getActiveBoard();
        Board& enemyBoard = this->currentGame->getOpponentBoard();

        this->view.showGameTurn(player, myBoard, enemyBoard);

        int row, col;
        bool valid = false;

        do {
            if (!this->view.getShotCoordinate(row, col)) {
                return;
            }

            char cell = enemyBoard.getCell(row, col);

            if (cell == 'X' || cell == 'O') {
                this->view.printMessage("Essa posicao ja foi atacada! Escolha outra.");
            }
            else {
                valid = true;
            }
        } while (!valid);

        string coord = string(1, 'A' + row) + to_string(col);
        char result = this->currentGame->executeMove(row, col);
        bool hit = (result == 'X');

        this->view.showShotResult(hit, coord);

        if (hit) {
            Utils::pressEnter();
        }

        if (!hit && !this->currentGame->isGameOver()) {
            Utils::pressEnter();

            string nextPlayer = this->currentGame->getCurrentPlayer()->getNickname();
            Utils::pressEnterConfirmPlayer(nextPlayer);
        }
    };
}