//
// Created by pedro on 16/05/2026.
//

#include "Board.h"
#include <iostream>
#include <random>
#include <algorithm>

Board::Board() {
    for (int i = 0; i < this->SIZE; ++i) {
        for (int j = 0; j < this->SIZE; ++j) {
            this->grid[i][j] = this->WATER;
        }
    }
}

bool Board::validatePosition(int row, int column, int size, bool horizontal) const {
    if (!isWithinBounds(row, column, size, horizontal))
        return false;

    int startRow = std::max(0, row - 1);
    int endRow   = std::min(this->SIZE - 1, horizontal ? row + 1 : row + size);
    int startCol = std::max(0, column - 1);
    int endCol   = std::min(this->SIZE - 1, horizontal ? column + size : column + 1);

    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            if (this->grid[i][j] != this->WATER) {
                return false;
            }
        }
    }

    return true;
}

bool Board::placeShip(const Ship& ship, int row, int column, bool horizontal) {
    Ship tempShip = ship;
    tempShip.setDirection(horizontal);

    if (validatePosition(row, column, tempShip.getSize(), horizontal)) {
        if (horizontal) {
            for (int j = column; j < column + tempShip.getSize(); ++j) {
                this->grid[row][j] = tempShip.getSymbol();
            }
        } else {
            for (int i = row; i < row + tempShip.getSize(); ++i) {
                this->grid[i][column] = tempShip.getSymbol();
            }
        }
        tempShip.setStartPosition(row, column);
        this->fleet.push_back(tempShip);
        return true;
    }
    return false;
}

char Board::registerShot(int row, int column) {
    if (row < 0 || row >= this->SIZE || column < 0 || column >= this->SIZE) {
        return this->MISS;
    }

    char currentCell = this->grid[row][column];

    if (currentCell != this->WATER && currentCell != this->HIT && currentCell != this->MISS) {
        this->grid[row][column] = this->HIT;

        for (size_t i = 0; i < this->fleet.size(); ++i) {
            if (isCellPartOfShip(row, column, this->fleet[i])) {
                this->fleet[i].addHit();
                break;
            }
        }
        return this->HIT;
    }

    if (currentCell == this->WATER) {
        this->grid[row][column] = this->MISS;
        return this->MISS;
    }

    return currentCell;
}

bool Board::allShipsSunk() const {
    if (this->fleet.empty()) {
        return false;
    }

    for (const Ship& s : this->fleet) {
        if (!s.isSunk()) {
            return false;
        }
    }
    return true;
}

int Board::getSize() const {
    return this->SIZE;
}

char Board::getCell(int row, int col) const {
    return grid[row][col];
}

const vector<Ship>& Board::getFleet() const {
    return this->fleet;
}

void Board::placeShipAutomatically(int size, const string& type, char symbol) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis_coord(0, SIZE - 1);
    std::uniform_int_distribution<> dis_dir(0, 1);

    bool placed = false;
    while (!placed) {
        int row_random = dis_coord(gen);
        int col_random = dis_coord(gen);
        bool horizontal_random = (dis_dir(gen) == 1);

        if (validatePosition(row_random, col_random, size, horizontal_random)) {
            Ship tempShip(type, size, symbol);
            placeShip(tempShip, row_random, col_random, horizontal_random);
            placed = true;
        }
    }
}

bool Board::isWithinBounds(int row, int col, int size, bool horizontal) const {
    if (row < 0 || row >= this->SIZE || col < 0 || col >= this->SIZE)
        return false;
    if (horizontal && col + size > this->SIZE)
        return false;
    if (!horizontal && row + size > this->SIZE)
        return false;
    return true;
}

bool Board::isCellPartOfShip(int row, int col, const Ship& ship) const {
    if (ship.getDirection()) {
        return row == ship.getStartRow() &&
               col >= ship.getStartCol() &&
               col < ship.getStartCol() + ship.getSize();
    } else {
        return col == ship.getStartCol() &&
               row >= ship.getStartRow() &&
               row < ship.getStartRow() + ship.getSize();
    }
}