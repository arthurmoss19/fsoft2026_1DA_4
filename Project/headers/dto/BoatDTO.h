//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_BOATDTO_H
#define FSOFT_BOATDTO_H

#include <string>

using namespace std;

struct BoatDTO {
    string type;
    int size;
    bool destroyed;
    int line;
    int column;
    bool direction;
};

#endif //FSOFT_BOATDTO_H