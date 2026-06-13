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
        system("cls");
        cout << "\nEntrada Invalida! Por favor insira um numero" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return -1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (number < min || number > max) {
        system("cls");
        cout << "\nEntrada invalida! A opcao tem de ser um dos numeros presentes no menu" << endl;
        return min - 1;
    }

    return number;
}
string Utils::getString(const string& label) {
    string input;
    cout << label << ": ";
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, input);
    return input;
}

void Utils::pressEnter(const string& message) {
    string input;

    do {
        cout << "\n" << message;
        getline(cin, input);

        if (!input.empty()) {
            cout << "\nApenas pressione ENTER, sem escrever nada...\n";
        }
    } while (!input.empty());
}

bool Utils::isNicknameValid(const string& nick, string& errorMsg) {
    if (nick.length() < 3 || nick.length() > 24) {
        errorMsg = "O nickname deve ter entre 3 e 24 caracteres,";
        return false;
    }

    string invalidChars;
    for (char c : nick) {
        if (c == ' ') {
            errorMsg = "O nickname nao pode ter espacos,";
            return false;
        }
        if (static_cast<unsigned char>(c) > 127) {
            if (!invalidChars.empty()) invalidChars += ", ";
            invalidChars += c;
        }
    }

    if (!invalidChars.empty()) {
        errorMsg = "O nickname nao pode conter o(s) caractere(s): " + invalidChars + ",";
        return false;
    }

    return true;
}