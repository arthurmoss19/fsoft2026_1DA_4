//
// Created by pedro on 12/06/2026.
//

#include "gtest/gtest.h"
#include "Player.h"
#include "InvalidDataException.h"


TEST(PlayerConstructorTest, ValidNickname) {
    bool flag = false;

    try {
        Player p("pedro");
    } catch (InvalidDataException& e) {
        flag = true;
    }

    EXPECT_FALSE(flag);
}

TEST(PlayerConstructorTest, NicknameTooShort) {
    bool flag = false;

    try {
        Player p("12");
    } catch (InvalidDataException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(PlayerConstructorTest, NicknameTooLong) {

    bool flag = false;

    try {
        Player p("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    } catch (InvalidDataException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}


TEST(PlayerRegisterShotTest, Hit) {

    Player p("pedro");
    p.registerShot(true);
    EXPECT_EQ(p.getTotalShots(), 1);
    EXPECT_EQ(p.getHits(), 1);
}

TEST(PlayerRegisterShotTest, Miss) {

    Player p("pedro");
    p.registerShot(false);
    EXPECT_EQ(p.getTotalShots(), 1);
    EXPECT_EQ(p.getHits(), 0);
}

TEST(PlayerRegisterGameOverTest, Win) {

    Player p("pedro");
    p.registerGameOver(true);
    EXPECT_EQ(p.getWins(), 1);
    EXPECT_EQ(p.getLosses(), 0);
}

TEST(PlayerRegisterGameOverTest, Loss) {

    Player p("pedro");
    p.registerGameOver(false);
    EXPECT_EQ(p.getWins(), 0);
    EXPECT_EQ(p.getLosses(), 1);
}


TEST(PlayerOperatorTest, EqualNickname) {

    Player p("pedro");
    EXPECT_TRUE(p == "pedro");
    EXPECT_FALSE(p == "outro");
}

TEST(PlayerAccuracyTest, AccuracyRate) {
    Player p("pedro");
    p.registerShot(true);
    p.registerShot(true);
    p.registerShot(false);
    EXPECT_NEAR(p.getAccuracyRate(), 66.66f, 0.1f);
}