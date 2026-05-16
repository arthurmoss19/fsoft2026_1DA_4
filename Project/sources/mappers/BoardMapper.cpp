//
// Created by tiago on 16/05/2026.
//

#include "../../headers/mappers/BoardMapper.h"
#include "../../headers/mappers/BoatMapper.h"

#include <algorithm>

void BoardMapper::model2DTO(const Board& board, BoardDTO& dto) {
    dto.size    = board.getSize();
    dto.allSunk = board.allShipsSunk();

    dto.grid.resize(dto.size, vector<char>(dto.size));
    for (int i = 0; i < dto.size; i++)
        for (int j = 0; j < dto.size; j++)
            dto.grid[i][j] = board.getCell(i, j);

    dto.fleet.clear();
    for (const Ship& ship : board.getFleet()) {
        BoatDTO boatDto;
        int row = -1, column = -1;

        for (int i = 0; i < dto.size && row == -1; i++)
            for (int j = 0; j < dto.size && row == -1; j++)
                if (dto.grid[i][j] == ship.getSymbol()) {
                    row    = i;
                    column = j;
                }

        BoatMapper::model2DTO(ship, row, column, boatDto);
        dto.fleet.push_back(boatDto);
    }
}

