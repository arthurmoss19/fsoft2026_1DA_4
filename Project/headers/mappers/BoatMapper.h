//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_BOATMAPPER_H
#define FSOFT_BOATMAPPER_H

#include "../model/Ship.h"
#include "../dto/BoatDTO.h"

class BoatMapper {
public:
    static void model2DTO(const Ship& ship, int row, int column, BoatDTO& dto);
    static void dto2Model(const BoatDTO& dto, Ship& boat);
};

#endif //FSOFT_BOATMAPPER_H