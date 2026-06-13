//
// Created by pedro on 13/06/2026.
//

#include "gtest/gtest.h"
#include "Board.h"
#include "Ship.h"

TEST(BoardConstructorTest, AllWater) {
    Board b;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            EXPECT_EQ(b.getCell(i, j), '~');
        }
    }
}


TEST(BoardPlaceShipTest, ValidPlacement) {
    Board b;
    Ship s("Fragata", 2, '#');

    bool result = b.placeShip(s, 0, 0, true);
    EXPECT_TRUE(result);
}



TEST(BoardPlaceShipTest, OutOfBounds) {
    Board b;
    Ship s("Fragata", 2, '#');

    bool result = b.placeShip(s, 9, 9, true);
    EXPECT_FALSE(result);
}

TEST(BoardPlaceShipTest, Overlap) {
    Board b;
    Ship s1("Fragata", 2, '#');
    Ship s2("Submarino", 3, '#');
    b.placeShip(s1, 0, 0, true);

    bool result = b.placeShip(s2, 0, 0, true);
    EXPECT_FALSE(result);
}