//
// Created by pedro on 12/06/2026.
//

#include "gtest/gtest.h"
#include "Ship.h"

TEST(ShipConstructorTest, ValidShip) {
    bool flag = false;

    try {
        Ship s("Fragata", 2, '#');
    } catch (...) {
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(ShipAddHitTest, HitsReceivedIncrements) {
    Ship s("Fragata", 2, '#');

    s.addHit();
    EXPECT_FALSE(s.isSunk());
}


TEST(ShipIsSunkTest, NotSunkBeforeAllHits) {
    Ship s("Fragata", 2, '#');

    s.addHit();
    EXPECT_FALSE(s.isSunk());
}

TEST(ShipIsSunkTest, SunkAfterAllHits) {
    Ship s("Fragata", 2, '#');

    s.addHit();
    s.addHit();
    EXPECT_TRUE(s.isSunk());
}