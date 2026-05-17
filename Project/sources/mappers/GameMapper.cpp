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

    if (game.getPlayer1() != nullptr)
        PlayerMapper::model2DTO(*game.getPlayer1(), dto.player1);
    if (game.getPlayer2() != nullptr)
        PlayerMapper::model2DTO(*game.getPlayer2(), dto.player2);

    BoardMapper::model2DTO(game.getBoard1(), dto.board1);
    BoardMapper::model2DTO(game.getBoard2(), dto.board2);
}
