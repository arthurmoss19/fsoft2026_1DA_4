//
// Created by arthu on 16/05/2026.
//

#include <iostream>
#include <limits>
#include "Utils.h"

using namespace std;

int Utils::getNumber(const string&  label){
    int number;
    bool flag = false;

    do {
        cout<<label<<": ";
        flag = false;
        cin >> number;
        if (cin.fail()) {
            cout << "Entrada Inválida, por favor insira um número" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            flag = true;
        }
    } while(flag == true);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
}