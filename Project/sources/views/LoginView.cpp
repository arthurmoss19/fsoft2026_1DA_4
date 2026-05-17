//
// Created by arthu on 17/05/2026.
//

#include "LogInView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

int LoginView::menuLogin() {
    int op = -1;
    do {
        cout << "\n\n********** Batalha Naval **********\n";
        cout << "1 - Tenho perfil\n";
        cout << "2 - Nao tenho perfil\n";
        cout << "\n0 - Sair\n";
        op = Utils::getNumber("Opcao", 0, 2);
    } while (op < 0 || op > 2);

    return op;
}

PlayerLoginDTO LoginView::getNewPlayer() {
    PlayerLoginDTO dto;
    cout << "\n********** Registar Novo Jogador **********\n";
    dto.nickname = Utils::getString("Nickname (3-24 caracteres)");
    return dto;
}

string LoginView::getNickname(const string& label) {
    return Utils::getString(label);
}
