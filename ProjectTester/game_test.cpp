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


TEST(GameIsVsComputerTest, JvsJ) {
    Player p1("pedro");
    Player p2("arthur");

    Game g(&p1, &p2, false, 0);
    EXPECT_FALSE(g.isVsComputer());
}


TEST(GameIsVsComputerTest, JvsComputer) {
    Player p1("pedro");

    Game g(&p1, nullptr, true, 1);

    EXPECT_TRUE(g.isVsComputer());
}


TEST(GameExecuteMoveTest, MissChangesTurn) {
    Player p1("pedro");
    Player p2("arthur");

    Game g(&p1, &p2, false, 0);

    g.executeMove(0, 0);

    EXPECT_EQ(g.getCurrentTurn(), 2);
}


TEST(GameExecuteMoveTest, HitKeepsTurn) {
    Player p1("pedro");
    Player p2("arthur");

    Game g(&p1, &p2, false, 0);
    Ship s("Fragata", 2, '#');

    g.getBoard2().placeShip(s, 0, 0, true);
    g.executeMove(0, 0);

    EXPECT_EQ(g.getCurrentTurn(), 1);
}