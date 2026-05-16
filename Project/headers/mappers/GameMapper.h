//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_GAMEMAPPER_H
#define FSOFT_GAMEMAPPER_H

#include "../model/Game.h"
#include "../dto/GameDTO.h"

class GameMapper {
public:
    static void model2DTO(const Game& game, GameDTO& dto);
};

#endif //FSOFT_GAMEMAPPER_H