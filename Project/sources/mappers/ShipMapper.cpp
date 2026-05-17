//
// Created by tiago on 16/05/2026.
//

#include "ShipMapper.h"

void ShipMapper::model2DTO(const Ship& ship, int row, int column, ShipDTO& dto) {
    dto.type      = ship.getType();
    dto.size      = ship.getSize();
    dto.direction = ship.getDirection();
    dto.destroyed = ship.isSunk();
    dto.line      = row;
    dto.column    = column;
}

void ShipMapper::dto2Model(const ShipDTO& dto, Ship& ship) {
    ship.setType(dto.type);
    ship.setDirection(dto.direction);
}