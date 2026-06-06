//
// Created by pedro on 16/05/2026.
//

#include <iostream>
#include "Board.h"
#include <random>

Board::Board() {
    for (int i = 0; i < this->SIZE; ++i) {
        for (int j = 0; j < this->SIZE; ++j) {
            this->grid[i][j] = this->WATER;
        }
    }
}

bool Board::validatePosition(int row, int column, int size, bool horizontal) const {
    if (row < 0 || row >= this->SIZE || column < 0 || column >= this->SIZE) {
        return false;
    }

    if (horizontal) {
        if (column + size > this->SIZE) {
            return false;
        }
        for (int j = column; j < column + size; ++j) {
            if (this->grid[row][j] != this->WATER) {
                return false;
            }
        }
    } else {
        if (row + size > this->SIZE) {
            return false;
        }
        for (int i = row; i < row + size; ++i) {
            if (this->grid[i][column] != this->WATER) {
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
            if (this->fleet[i].getSymbol() == currentCell) {
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

void Board::print(bool hideShips) const {
    cout << "  ";
    for (int j = 0; j < this->SIZE; ++j) {
        cout << j << " ";
    }
    cout << "\n";

    for (int i = 0; i < this->SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < this->SIZE; ++j) {
            char cell = this->grid[i][j];
            if (hideShips && cell != this->WATER && cell != this->HIT && cell != this->MISS) {
                cout << this->WATER << " ";
            } else {
                cout << cell << " ";
            }
        }
        cout << "\n";
    }
}

bool Board::allShipsSunk() const {
    if (this->fleet.empty()) {
        return false;
    }

    for (vector<Ship>::const_iterator it = this->fleet.begin(); it != this->fleet.end(); ++it) {
        if (!it->isSunk()) {
            return false;
        }
    }
    return true;
}

int Board::getSize() const {
    return this->SIZE;
}

char Board::getCell(int row, int column) const {
    return grid[row][column];
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