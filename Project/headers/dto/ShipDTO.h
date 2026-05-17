//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_SHIPDTO_H
#define FSOFT_SHIPDTO_H

#include <string>

using namespace std;

struct ShipDTO {
    string type;
    int size;
    bool destroyed;
    int line;
    int column;
    bool direction;
};

#endif