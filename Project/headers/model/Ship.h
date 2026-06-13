//
// Created by pedro on 14/05/2026.
//

#ifndef PROJETOFSOFT_SHIP_H
#define PROJETOFSOFT_SHIP_H

#include <string>
#include <vector>

using namespace std;

class Ship {
private:
    string type;
    int size;
    int hitsReceived;
    int startRow;
    int startCol;
    char symbol;
    bool direction;
    bool isSizeValid(int size);
    bool isTypeValid(const string& type);
    void setSize(int size);

public:
    Ship(const string& type, int size, char symbol);
    Ship(const Ship& obj);
    ~Ship() = default;
    const string& getType() const;
    void setType(const string& type);
    int getSize() const;
    char getSymbol() const;
    void setSymbol(char symbol);
    bool getDirection() const;
    void setDirection(bool direction);
    bool isSunk() const;
    void addHit();
    void setStartPosition(int row, int col);
    int getStartRow() const;
    int getStartCol() const;
    bool operator == (const Ship& obj) const;
    bool operator == (const string& type) const;
};

#endif