//
// Created by pedro on 12/06/2026.
//

#include "gtest/gtest.h"
#include "Game.h"
#include "Player.h"
#include "Ship.h"

TEST(GameConstructorTest, ValidGame) {
    Player p1("pedro");
    Player p2("arthur");

    Game g(&p1, &p2, false, 0);

    EXPECT_FALSE(g.isGameOver());
    EXPECT_EQ(g.getCurrentTurn(), 1);
}