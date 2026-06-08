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

void Utils::pressEnterMainMenu() {

    string input;
    do {
        cout << "Pressione ENTER para voltar ao menu principal...";
        getline(cin, input);
        if (!input.empty()) {
            cout << "Apenas pressione ENTER, sem escrever nada...\n";
        }
    } while (!input.empty());
}

void Utils::pressEnterPlayerSwitch(const string& player) {
    string input;
    do {
        cout << "Pressione ENTER e passe o computador para " << player << "...";
        getline(cin, input);
        if (!input.empty()) {
            cout << "Apenas pressione ENTER, sem escrever nada...\n";
        }
    } while (!input.empty());
}

void Utils::pressEnterConfirmPlayer(const string& player) {
    string input;
    do {
        cout << "Passe o computador para " << player << "\n";
        cout << "Pressione ENTER...";
        getline(cin, input);
        if (!input.empty()) {
            cout << "Apenas pressione ENTER, sem escrever nada...\n";
        }
    } while (!input.empty());
}

void Utils::pressEnter() {
    string input;
    do {
        cout << "Pressione ENTER...";
        getline(cin, input);
        if (!input.empty()) {
            cout << "Apenas pressione ENTER, sem escrever nada...\n\n";
        }
    } while (!input.empty());
}