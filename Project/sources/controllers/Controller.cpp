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
                bool jogador2nick = false;
                int op2 = -1;
                do {
                    op2 = this->loginView.menuLogin("********** Jogador 2 - Login **********");
                    switch (op2) {
                        case 1: {
                            nick2 = loginView.getNickname("Nickname do jogador 2");
                            try {
                                this->playerService->getPlayer(nick2);
                                jogador2nick = true;
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
                                jogador2nick = true;
                            } catch (InvalidDataException &e) {
                                this->view.printMessage(e.what());
                            } catch (DuplicatedDataException &e) {
                                this->view.printMessage(e.what());
                            }
                            break;
                        }
                        case 0: jogador2nick = true;
                    }
                } while (!jogador2nick && op2 != 0);

                if (jogador2nick && op2 != 0) {
                    Player* p1 = this->playerContainer->get(this->currentNickname);
                    Player* p2 = this->playerContainer->get(nick2);
                    this->currentGame = new Game(p1, p2, false, 0);

                    this->view.printMessage("\n*** Jogador 1: " + p1->getNickname() + " — posiciona os teus navios ***");
                    runPlacement(this->currentGame->getBoard1());

                    Utils::pressEnter();
                    system("cls");

                    this->view.printMessage("\n*** Jogador 2: " + p2->getNickname() + " — posiciona os teus navios ***");
                    runPlacement(this->currentGame->getBoard2());

                    system("cls");
                    this->view.printMessage("\nPreparacao concluida! O jogo vai comecar...");
                    return;
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
    Utils::pressEnter();
}

void Controller::runPlacement(Board& board) {
    if (this->currentGame == nullptr) {
        return;
    }
    vector<pair<int, string>> frota = {
        {5, "Porta-Avioes"},
        {4, "Navio-Tanque"},
        {3, "Submarino"},
        {3, "Fragata"},
        {2, "Navio-Patrulha"}
    };
    char simboloNavio = '#';
    int modoOpcao = this->view.menuShipPlacement();
    if (modoOpcao == 0) {
        return;
    }
    if (modoOpcao == 1) {
        for (const auto& navio : frota) {
            bool sucesso = false;
            while (!sucesso) {
                this->view.printMessage("\n-> Posicionar " + navio.second + " (Tamanho " + to_string(navio.first) + "):");

                int linha = Utils::getNumber("Linha de inicio (0 a 9)", 0, 9);

                int coluna = Utils::getNumber("Coluna de inicio (0 a 9)", 0, 9);

                string orientacao = Utils::getString("Orientacao (H - Horizontal, V - Vertical)");

                bool horizontal = (orientacao == "H" || orientacao == "h");
                Ship oNavio(navio.second, navio.first, simboloNavio);
                sucesso = board.placeShip(oNavio, linha, coluna, horizontal);
                if (!sucesso) {
                    this->view.printMessage("[ERRO] Posicao invalida ou sobreposta! Tente novamente.");
                }
            }
            board.print(false);
        }
        this->view.printMessage("\n[SUCESSO] Todos os teus navios foram posicionados manualmente!");
    } else {
        this->view.printMessage("\nA gerar posicoes aleatorias para a sua frota...");
        for (const auto& navio : frota) {
            board.placeShipAutomatically(navio.first, navio.second, simboloNavio);
        }
        board.print(false);
        this->view.printMessage("[SUCESSO] A tua frota foi gerada com sucesso!");
    }
}