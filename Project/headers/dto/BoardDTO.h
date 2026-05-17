//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_BOARDDTO_H
#define FSOFT_BOARDDTO_H

#include <vector>
#include "ShipDTO.h"

using namespace std;

struct BoardDTO {
    int size;
    vector<vector<char>> grid;
    vector<BoatDTO> fleet;
    bool allSunk;
};

#endif //FSOFT_BOARDDTO_H