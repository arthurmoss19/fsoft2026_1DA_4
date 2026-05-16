//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_PLAYERDTO_H
#define FSOFT_PLAYERDTO_H

#include <string>

using namespace std;

struct PlayerDTO {
    string nickname;
    int victories;
    int defeats;
    int totalShots;
    int shotsHit;
    float accuracy;
};

#endif //FSOFT_PLAYERDTO_H