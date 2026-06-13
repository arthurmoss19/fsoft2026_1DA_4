//
// Created by tiago on 16/05/2026.
//

#include "GameMapper.h"
#include "PlayerMapper.h"
#include "BoardMapper.h"

void GameMapper::model2DTO(const Game& game, GameDTO& dto) {
    dto.currentRound    = game.getCurrentTurn();
    dto.againstComputer = game.isVsComputer();
    dto.dificultyAI     = game.getAiDifficulty();
    dto.gameFinished    = game.isGameOver();
}
