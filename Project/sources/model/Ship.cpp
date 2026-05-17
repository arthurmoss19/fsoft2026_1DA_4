//
// Created by pedro on 16/05/2026.
//

#include "Ship.h"
#include "InvalidDataException.h"

bool Ship::isSizeValid(int size) {
    if (size >= 2 && size <= 5) {
        return true;
    }
    else {
        return false;
    }
}

bool Ship::isTypeValid(const string& type) {
    if (type.length() >= 3 && type.length() <= 20) {
        return true;
    }
    else {
        return false;
    }
}

void Ship::setSize(int size) {
    if (isSizeValid(size)) {
        this ->size = size;
    }
    else {
        string msg = "Ship " + type;
        throw InvalidDataException(msg);
    }
}

void Ship::setType(const string& type) {
    if (isTypeValid(type)) {
        this ->type = type;
    }
    else {
        string msg = "Ship " + type;
        throw InvalidDataException(msg);
    }
}

Ship::Ship(const string& type, int size, char symbol) {
    setType(type);
    setSize(size);
    this->symbol = symbol;
    this->hitsReceived = 0;
    this ->direction = true;
}

Ship::Ship(const Ship& obj) {
    setType(obj.type);
    setSize(obj.size);
    this->symbol = obj.symbol;
    this->hitsReceived = obj.hitsReceived;
    this->direction = obj.direction;
}

const string& Ship::getType() const {
    return type;
}

int Ship::getSize() const {
    return size;
}

char Ship::getSymbol() const {
    return symbol;
}

void Ship::setSymbol(char symbol) {
    this->symbol = symbol;
}

bool Ship::getDirection() const {
    return direction;
}

void Ship::setDirection(bool direction) {
    this->direction = direction;
}

bool Ship::isSunk() const {
    if (hitsReceived >= size) {
        return true;
    }
    return false;
}

void Ship::addHit() {
    if (hitsReceived < size) {
        hitsReceived++;
    }
}

bool Ship::operator == (const Ship& obj) const {
    if (this->type == obj.type) {
        return true;
    }
    return false;
}

bool Ship::operator == (const string& type) const {
    if (this->type == type) {
        return true;
    }
    return false;
}