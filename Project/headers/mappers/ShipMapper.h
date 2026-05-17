//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_SHIPMAPPER_H
#define FSOFT_SHIPMAPPER_H

#include "../model/Ship.h"
#include "../dto/ShipDTO.h"

class ShipMapper {
public:
    static void model2DTO(const Ship& ship, int row, int column, ShipDTO& dto);
    static void dto2Model(const ShipDTO& dto, Ship& boat);
};

#endif