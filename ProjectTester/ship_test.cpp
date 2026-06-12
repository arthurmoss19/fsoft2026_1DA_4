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