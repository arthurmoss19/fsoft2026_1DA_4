//
// Created by arthu on 14/05/2026.
//

#include<iostream>
#include "View.h"

using namespace std;

View::View() {
}

int View::menuMain() {
    int op = -1;
    do {
        cout <<"\n\n********** Menu Principal **********\n";
        cout <<"1. Novo Jogo\n";
        cout <<"2. Ranking\n";
        cout <<"3. Estatísticas\n";
        cout <<"4. Ajuda e Regras\n";
        cout <<"\n0. Sair\n";
        op = Utils::getNumber("Opção");

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
        op = Utils::getNumber("Opção");
    } while (op < 0 || op > 2);
    return op;
}

int View::menuDifficulty() {
    int op = -1;
    do {
        cout <<"\n\n********** Dificuldade **********\n";
        cout <<"1. Fácil\n";
        cout <<"2. Difícil\n";
        cout <<"\n0. Sair\n";
        op = Utils::getNumber("Opção");
    } while (op < 0 || op > 2);
    return op;
}

int View::menuShipPlacement() {
    int op = -1;
    do {
        cout <<"\n\n********** Posicionamento dos Navios **********\n";
        cout <<"1. Posicionar Manual\n";
        cout <<"2. Posicionamento Automático\n";
        cout <<"\n0. Sair\n";
        op = Utils::getNumber("Opção");
    } while (op < 0 || op > 2);
    return op;
}