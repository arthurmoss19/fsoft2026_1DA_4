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