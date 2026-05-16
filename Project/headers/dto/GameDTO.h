//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_GAMEDTO_H
#define FSOFT_GAMEDTO_H

#include "PlayerDTO.h"
#include "BoardDTO.h"

struct GameDTO {
    PlayerDTO player1;
    PlayerDTO player2;
    BoardDTO board1;
    BoardDTO board2;
    int currentRound;
    bool againstComputer;
    int dificultyAI;
    bool gameFinished;
};

#endif //FSOFT_GAMEDTO_H