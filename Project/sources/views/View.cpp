//
// Created by arthu on 14/05/2026.
//

#include<iostream>
#include "View.h"
#include "Utils.h"

using namespace std;

View::View() {
}

int View::menuMain() {
    int op = -1;

    do {
        cout <<"\n\n********** Menu Principal **********\n";
        cout <<"1. Novo Jogo\n";
        cout <<"2. Ranking\n";
        cout <<"3. Estatisticas\n";
        cout <<"4. Ajuda e Regras\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 4);

    return op;
}

int View::menuNewGame() {
    int op = -1;

    do {
        cout <<"\n\n********** Novo Jogo **********\n";
        cout <<"1. Jogador vs. Computador\n";
        cout <<"2. Jogador vs. Jogador\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 2);

    return op;
}

int View::menuDifficulty() {
    int op = -1;

    do {
        cout <<"\n\n********** Dificuldade **********\n";
        cout <<"1. Facil\n";
        cout <<"2. Dificil\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 2);

    return op;
}

int View::menuShipPlacement() {
    int op = -1;

    do {
        cout <<"\n\n********** Posicionamento dos Navios **********\n";
        cout <<"1. Posicionamento manual\n";
        cout <<"2. Posicionamento automatico\n";
        cout <<"\n0. Sair\n";

        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 2);

    return op;
}

int View::menuRankingType() {
    int op = -1;

    do {
        cout << "\n\n********** Tipo de Ranking **********\n";
        cout << "1. Número de vitorias\n";
        cout << "2. Taxa de precisao\n";
        cout << "\n0. Sair\n";

        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 2);

    return op;
}

int View::menuStatistics() {

}

void View::printHelpAndRules() {
    cout << "\n\n********** Ajuda e Regras **********\n";

    cout << "\nObjetivo do jogo:\n";
    cout << "- Afundar todos os navios do adversario antes que ele afunde os seus\n";

    cout << "\nComo jogar:\n";
    cout << "- Cada jogador possui 5 navios e um tabuleiro 10x10\n";
    cout << "- Cada jogador posiciona os navios no tabuleiro em segredo\n";
    cout << "- O jogo comeca!\n";

    cout << "\nExemplo de turno:\n";
    cout << "- Jogador 1 escolhe a coordenada B4\n";
    cout << "- Se houver navio em B4, e um tiro certo\n";
    cout << "- Caso contrario, e um tiro falhado\n";

    cout << "\nLegenda do Tabuleiro:\n";
    cout << " ~ Agua\n";
    cout << " # Navio\n";
    cout << " X Navio atingido (tiro certo)\n";
    cout << " O Tiro na agua (tiro falhado)\n";
    cout << "\nOutras Regras\n";

    cout << "- Nao pode mudar os navios de lugar durante o jogo\n";
    cout << "- Cada jogador joga uma vez por turno\n";
    cout << "- Ganha quem destruir todos os navios inimigos\n";

    cout << "\nAgora voce ja esta pronto para jogar Batalha Naval!\n";
    cout << "Boa sorte e bom jogo!\n\n";
}