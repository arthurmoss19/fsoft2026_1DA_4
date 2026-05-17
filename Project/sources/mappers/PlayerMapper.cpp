//
// Created by tiago on 16/05/2026.
//

#include "PlayerMapper.h"

void PlayerMapper::model2DTO(const Player& player, PlayerDTO& dto) {
    dto.nickname   = player.getNickname();
    dto.victories  = player.getWins();
    dto.defeats    = player.getLosses();
    dto.totalShots = player.getTotalShots();
    dto.shotsHit   = player.getHits();
    dto.accuracy   = player.getAccuracyRate();
}

void PlayerMapper::dto2Model(const PlayerDTO& dto, Player& player) {
    player.setNickname(dto.nickname);
}