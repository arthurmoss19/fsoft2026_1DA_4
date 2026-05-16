//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_PLAYERMAPPER_H
#define FSOFT_PLAYERMAPPER_H

#include "../model/Player.h"
#include "../dto/PlayerDTO.h"

class PlayerMapper {
public:
    static void model2DTO(const Player& player, PlayerDTO& dto);
    static void dto2Model(const PlayerDTO& dto, Player& player);
};

#endif //FSOFT_PLAYERMAPPER_H