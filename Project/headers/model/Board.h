//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_BOARD_H
#define PROJETOFSOFT_BOARD_H

#include <vector>
#include "Ship.h"

using namespace std;

class Board {
private:
    static const int SIZE = 10;
    char grid[SIZE][SIZE];
    vector<Ship> fleet;
    static const char WATER = '~';
    static const char SHIP = '#';
    static const char HIT = 'X';
    static const char MISS = 'O';

public:
    friend class BoardMapper;
    Board();
    ~Board() = default;
    bool validatePosition(int row, int column, int size, bool horizontal) const;
    bool placeShip(const Ship& ship, int row, int column, bool horizontal);
    void placeShipAutomatically(int size, const string& type, char symbol);
    char registerShot(int row, int column);
    void print(bool hideShips) const;
    bool allShipsSunk() const;
    int getSize() const;
    char getCell(int row, int column) const;
    const vector<Ship>& getFleet() const;
    bool isWithinBounds(int row, int column, int size, bool horizontal) const;
};

#endif