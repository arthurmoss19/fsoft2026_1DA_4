//
// Created by tiago on 16/05/2026.
//

#include "BoardMapper.h"
#include "ShipMapper.h"

void BoardMapper::model2DTO(const Board& board, BoardDTO& dto) {
    dto.size    = board.getSize();
    dto.allSunk = board.allShipsSunk();

    dto.grid.resize(dto.size, vector<char>(dto.size));
    for (int i = 0; i < dto.size; i++)
        for (int j = 0; j < dto.size; j++)
            dto.grid[i][j] = board.getCell(i, j);

    dto.fleet.clear();
    for (const Ship& ship : board.getFleet()) {
        ShipDTO boatDto;
        ShipMapper::model2DTO(ship, boatDto);
        dto.fleet.push_back(boatDto);
    }
}

