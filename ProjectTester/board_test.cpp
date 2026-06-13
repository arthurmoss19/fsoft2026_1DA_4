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