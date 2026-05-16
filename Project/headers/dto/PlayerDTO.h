//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_PLAYERDTO_H
#define FSOFT_PLAYERDTO_H

#include <string>

using namespace std;

struct PlayerDTO {
    string nickname;
    int vitorias;
    int derrotas;
    int totalTiros;
    int tirosAcertados;
    float taxaPrecisao;
};

#endif //FSOFT_PLAYERDTO_H