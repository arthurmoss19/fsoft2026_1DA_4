//
// Created by tiago on 16/05/2026.
//

#ifndef FSOFT_BOARDMAPPER_H
#define FSOFT_BOARDMAPPER_H

#include "../model/Board.h"
#include "../dto/BoardDTO.h"

class BoardMapper {
public:
    static void model2DTO(const Board& board, BoardDTO& dto);
};

#endif //FSOFT_BOARDMAPPER_H