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
    this -> playerContainer -> loadFromFile("players.txt");
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
                system("cls");
                view.printMessage("Login: Entrar com conta\n");
                string nick = loginView.getNickname("Nickname");
                try {
                    playerService -> getPlayer(nick);
                    currentNickname = nick;
                    system("cls");
                    runMain();
                    op = 0;
                } catch (NoDataException& e) {
                    system("cls");
                    this->view.printMessage(e.what());
                }
                break;
            }
            case 2: {
                system("cls");
                PlayerLoginDTO dto = loginView.getNewPlayer();
                try {
                    playerService -> registerPlayer(dto);
                    currentNickname = dto.nickname;
                    this -> playerContainer -> saveToFile("players.txt");
                    view.printMessage("\nPerfil criado com sucesso! Bem-vindo, " + currentNickname + "!\n");
                    system("cls");
                    view.printMessage("Perfil criado com sucesso! Bem-vindo, " + currentNickname + "!\n");
                    op = 0;
                    runMain();
                } catch (InvalidDataException& e) {
                    system("cls");
                    this->view.printMessage(e.what());
                } catch (DuplicatedDataException& e) {
                    system("cls");
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
        this->view.printMessage("---------- Batalha Naval ----------");

        op = this -> view.menuMain();
        switch(op) {
            case 1:
                system("cls");
                runNewGame();
                break;
            case 2:
                system("cls");
                runRankingType();
                break;
            case 3:
                system("cls");
                runStatistics();
                break;
            case 4:
                system("cls");
                runHelpAndRules();
                break;
            default:
                break;
        }
    } while (op != 0);
    system("cls");
}

void Controller::runNewGame() {
    int op = -1;
    do {
        op = this->view.menuNewGame();
        switch (op) {
            case 1:
                {
                    system("cls");
                    this->view.printMessage("********** Modo de jogo: Jogador vs Computador **********");

                    int diff = this->view.menuDifficulty();
                    system("cls");
                    if (diff == 0) break;
                    Player* p1 = this->playerContainer->get(this->currentNickname);
                    this->currentGame = new Game(p1, nullptr, true, diff);

                    this->view.printMessage("********** " + p1->getNickname() + " - posiciona os teus navios **********");

                    if (!runPlacement(this->currentGame->getBoard1())) {
                        delete this->currentGame;
                        this->currentGame = nullptr;
                        system("cls");
                        return;
                    }

                    const auto& fleet = Game::getFleet();
                    for (const auto& ship : fleet) {
                        this->currentGame->getBoard2().placeShipAutomatically(ship.size, ship.type, '#');
                    }

                    system("cls");
                    op = 0;
                    runGameLoop();

                    break;
                }
            case 2: {
                system("cls");
                this->view.printMessage("********** Modo de jogo: Jogador vs Jogador **********");
                string nick2;
                bool player2nick = false;
                int op2 = -1;
                do {
                    op2 = this->loginView.menuLogin("********** Login do Jogador 2 **********");
                    switch (op2) {
                        case 1: {
                            system("cls");
                            this->view.printMessage("********** Modo de jogo: Jogador vs Jogador **********\n");
                            this->view.printMessage("********** Login do Jogador 2 **********\n");

                            nick2 = loginView.getNickname("Nickname do jogador 2");
                            try {
                                this->playerService->getPlayer(nick2);
                                system("cls");
                                player2nick = true;
                            } catch (NoDataException &e) {
                                system("cls");
                                this->view.printMessage("********** Modo de jogo: Jogador vs Jogador **********\n");
                                this->view.printMessage(e.what());
                            }
                            break;
                        }
                        case 2: {
                            system("cls");
                            this->view.printMessage("********** Modo de jogo: Jogador vs. Jogador **********\n");
                            PlayerLoginDTO dto = this->loginView.getNewPlayer();
                            if (dto.nickname == currentNickname)
                            {
                                this->view.printMessage("\nO nickname do jogador 2 tem de ser diferente do jogador 1!");
                                break;
                            }

                            try {
                                this->playerService->registerPlayer(dto);
                                nick2 = dto.nickname;
                                system("cls");
                                this->view.printMessage("Perfil criado com sucesso! Bem-vindo, " + nick2 + "!\n");
                                player2nick = true;
                            } catch (InvalidDataException &e) {
                                system("cls");
                                this->view.printMessage("********** Modo de jogo: Jogador vs Jogador **********\n");
                                this->view.printMessage(e.what());
                            } catch (DuplicatedDataException &e) {
                                system("cls");
                                this->view.printMessage("********** Modo de jogo: Jogador vs Jogador **********\n");
                                this->view.printMessage(e.what());
                            }
                            break;
                        }
                        case 0: player2nick = true;
                    }
                } while (!player2nick && op2 != 0);

                if (op2 == 0) {
                    system("cls");
                }

                if (player2nick && op2 != 0) {
                    Player* p1 = this->playerContainer->get(this->currentNickname);
                    Player* p2 = this->playerContainer->get(nick2);
                    this->currentGame = new Game(p1, p2, false, 0);

                    this->view.printMessage("\n********** Jogador 1: " + p1->getNickname() + " - posiciona os teus navios **********");

                    if (!runPlacement(this->currentGame->getBoard1())) {
                        delete this->currentGame;
                        this->currentGame = nullptr;
                        system("cls");
                        return;
                    }
                    system("cls");

                    this->view.printMessage("Os teus navios foram todos posicionados com sucesso!\n");
                    Utils::pressEnterPlayerSwitch(nick2);

                    system("cls");
                    this->view.printMessage("\n********** Jogador 2: " + p2->getNickname() + " - posiciona os teus navios **********");

                    if (!runPlacement(this->currentGame->getBoard2())) {
                        delete this->currentGame;
                        this->currentGame = nullptr;
                        system("cls");
                        return;
                    }

                    system("cls");

                    this->view.printMessage("Os teus navios foram todos posicionados com sucesso!\n");
                    this->view.printMessage("\nPreparacao concluida! O jogo vai comecar!\n");


                    Utils::pressEnter();
                    system("cls");
                    Utils::pressEnterConfirmPlayer(currentNickname);
                    system("cls");

                    runGameLoop();
                    op = 0;
                }
                break;
            }
        }
        if (op == 0) {
            system("cls");
        }
    } while (op != 0);
}

void Controller::runRankingType() {
    int op = -1;
    do {
        op = this->view.menuRankingType();
        switch (op) {
            case 1: {
                system("cls");
                list<PlayerDTO> ranking = this->playerService->getRankingByWins();
                this->view.printMessage("\n********** Ranking por Numero de Vitorias **********");
                int pos = 1;
                for (const PlayerDTO &p: ranking) {
                    this->view.printMessage(to_string(pos) + ". " + p.nickname + " - " + to_string(p.victories) + " vitorias");
                    pos++;
                }
                break;
                system("cls");
            }
            case 2: {
                system("cls");
                list<PlayerDTO> ranking = this->playerService->getRankingByAccuracy();
                this->view.printMessage("\n********** Ranking por Taxa de Precisao **********");
                int pos = 1;
                for (const PlayerDTO &p: ranking) {
                    this->view.printMessage(to_string(pos) + ". " + p.nickname + " - " + to_string(p.accuracy) + "%");
                    pos++;
                }
                break;
                system("cls");
            }
        }
        if (op == 0) {
            system("cls");
        }
    }while (op != 0);
}

void Controller::runStatistics() {
    int op = -1;
    do {
        op = this -> view.menuStatistics();
        switch(op) {
            case 1: {
                system("cls");
                this->view.printMessage("********** As Minhas Estatisticas **********\n");
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
                system("cls");
                case 2: {
                    system("cls");
                    this->view.printMessage("**********  Consultar outro Jogador ********** \n");

                    string nick = this -> loginView.getNickname("\nIntroduza o nickname de um jogador");
                    try {
                        system("cls");
                        this->view.printMessage("********** Estatisticas de " + nick + " **********\n");

                        PlayerDTO stats = this->playerService->getPlayer(nick);
                        this->view.printMessage("\nNickname: " + stats.nickname);
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
                system("cls");
        }

        if (op == 0) {
            system("cls");
        }

    } while (op != 0);
}

void Controller::runHelpAndRules() {
    this->view.printHelpAndRules();
    Utils::pressEnterMainMenu();
    system("cls");
}

void Controller::placeFleetManually(Board& board) {
    system("cls");
    this->view.showBoard(board, false);
    const auto& fleet = Game::getFleet();
    for (const auto& ship : fleet) {
        bool placed = false;
        while (!placed) {
            int row, col;
            bool horizontal;
            this->view.ShipPlacement(ship.type, ship.size, row, col, horizontal);

            if (!board.isWithinBounds(row, col, ship.size, horizontal)) {
                system("cls");
                this->view.showOutOfBoundsError();
                this->view.showBoard(board, false);
                continue;
            }

            bool overlap = false;

            if (horizontal) {
                for (int j = col; j < col + ship.size; ++j) {
                    if (board.getCell(row, j) != '~') {
                        overlap = true; break;
                    }
                }
            } else {
                for (int i = row; i < row + ship.size; ++i) {
                    if (board.getCell(i, col) != '~') {
                        overlap = true; break;
                    }
                }
            }

            if (overlap) {
                system("cls");
                this->view.showOverlapError();
                this->view.showBoard(board, false);
                continue;
            }

            Ship newShip(ship.type, ship.size, '#');
            placed = board.placeShip(newShip, row, col, horizontal);
            if (!placed) {
                system("cls");
                this->view.printMessage("Os navios nao podem encostar uns nos outros! Deve haver pelo menos uma casa de agua entre eles.\n");
                this->view.showBoard(board, false);
            }
        }
        system("cls");
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
            system("cls");
            this->view.printMessage("Modo de Posicionamento: Manual\n");
            this->placeFleetManually(board);
        } else {
            system("cls");
            this->view.printMessage("Modo de Posicionamento: Automatico\n");
            for (const auto& ship : fleet) {
                board.placeShipAutomatically(ship.size, ship.type, '#');
            }
            this->view.showBoard(board, false);
        }

        int opt = this->view.menuSatisfaction();
        switch (opt) {
        case 1:
                ready = true;
                break;
        case 2:
                modo = 2;
                break;
        case 3:
                modo = 1;
                break;
        case 0:
                system("cls");
                return false;

        }
    }

    this->view.showPlacementSuccess();
    return true;
}

void Controller::runGameLoop()
{
    if (this->currentGame == nullptr) return;

    while (!this->currentGame->isGameOver())
    {
        if (this->currentGame->isVsComputer() && this->currentGame->getCurrentTurn() == 2) {
            int row, col;
            bool hit;
            this->currentGame->computerMove(row, col, hit);

            string coord = string(1, 'A' + row) + to_string(col);
            this->view.printMessage("\nComputador atirou em " + coord + (hit ? ": NAVIO!\n" : ": AGUA!\n"));

            Utils::pressEnter();
            system("cls");
            continue;
        }

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
                this->view.printMessage("\nEssa posicao ja foi atacada! Escolha outra.");
            }
            else {
                valid = true;
            }
        }
        while (!valid);

        string coord = string(1, 'A' + row) + to_string(col);
        char result = this->currentGame->executeMove(row, col);
        bool hit = (result == 'X');

        this->view.showShotResult(hit, coord);

        if (hit) {
            Utils::pressEnter();
            system("cls");
        }

        if (!hit && !this->currentGame->isGameOver()) {
            Utils::pressEnter();
            system("cls");

            if (!this->currentGame->isVsComputer()) {
                string nextPlayer = this->currentGame->getCurrentPlayer()->getNickname();
                Utils::pressEnterConfirmPlayer(nextPlayer);
            }
            system("cls");
        }
    }

    if (this->currentGame->isVsComputer()) {
        Player* p1 = this->currentGame->getPlayer1();
        bool playerWon = this->currentGame->getBoard2().allShipsSunk();

        if (playerWon) {
            this->playerService->updateStats(p1->getNickname(), true, p1->getTotalShots(), p1->getHits());
            this->view.showGameOver(p1->getNickname(), p1->getTotalShots(), p1->getHits(),
                                    "Computador", 0, 0);
        }
        else {
            this->playerService->updateStats(p1->getNickname(), false, p1->getTotalShots(), p1->getHits());
            this->view.showGameOver("Computador", 0, 0,
                                    p1->getNickname(), p1->getTotalShots(), p1->getHits());
        }
    }
    else {
        Player* winner = this->currentGame->getCurrentPlayer();
        Player* loser = (winner == this->currentGame->getPlayer1())
                        ? this->currentGame->getPlayer2()
                        : this->currentGame->getPlayer1();

        this->playerService->updateStats(winner->getNickname(), true, winner->getTotalShots(), winner->getHits());
        this->playerService->updateStats(loser->getNickname(), false, loser->getTotalShots(), loser->getHits());

        this->view.showGameOver (
            winner->getNickname(), winner->getTotalShots(), winner->getHits(),
            loser->getNickname(), loser->getTotalShots(), loser->getHits()
        );
    }
    Utils::pressEnterMainMenu();
    system("cls");

    this->playerContainer->saveToFile("players.txt");

    delete this->currentGame;
    this->currentGame = nullptr;
}