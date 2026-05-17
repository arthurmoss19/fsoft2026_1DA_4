//
// Created by arthu on 16/05/2026.
//

#include <iostream>
#include <limits>
#include "Utils.h"

using namespace std;

int Utils::getNumber(const string&  label, int min, int max){
    int number;

    cout<<label<<": ";
    cin >> number;

    if (cin.fail()) {
        cout << "Entrada Invalida! Por favor insira um numero" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return -1;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (number < min || number > max) {
        cout << "Entrada invalida! A opcao tem de ser um dos numeros acima " << endl;
        return min - 1;
    }

    return number;
}
string Utils::getString(const string&  label){
    string input;
    cout<<label<<": ";
    getline (cin, input);

    return input;
}

void Utils::pressEnter() {
    cout << "Pressione ENTER para voltar ao menu principal...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}