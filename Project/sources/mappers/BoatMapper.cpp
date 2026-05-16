//
// Created by tiago on 16/05/2026.
//

#include "../../headers/mappers/BoatMapper.h"

void BoatMapper::model2DTO(const Ship& ship, int row, int column, BoatDTO& dto) {
    dto.type      = ship.getType();
    dto.size      = ship.getSize();
    dto.direction = ship.getDirection();
    dto.destroyed = ship.isSunk();
    dto.line      = row;
    dto.column    = column;
}

void BoatMapper::dto2Model(const BoatDTO& dto, Ship& ship) {
    ship.setType(dto.type);
    ship.setDirection(dto.direction);
}