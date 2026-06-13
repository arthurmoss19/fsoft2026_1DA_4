//
// Created by pedro on 13/06/2026.
//

#include "gtest/gtest.h"
#include "PlayerContainer.h"
#include "NoDataException.h"

TEST(PlayerContainerAddTest, AddAndGet) {
    PlayerContainer pc;

    pc.add("pedro");
    Player* p = pc.get("pedro");

    EXPECT_NE(p, nullptr);
    EXPECT_TRUE(*p == "pedro");
}


TEST(PlayerContainerGetTest, GetNonExistent) {
    PlayerContainer pc;
    bool flag = false;

    try {
        pc.get("jogadornaoexiste");
    } catch (NoDataException& e) {
        flag = true;
    }

    EXPECT_TRUE(flag);
}


TEST(PlayerContainerSearchTest, SearchExistent) {
    PlayerContainer pc;
    pc.add("pedro");

    Player* p = pc.search("pedro");
    EXPECT_NE(p, nullptr);
}

TEST(PlayerContainerSearchTest, SearchNonExistent) {
    PlayerContainer pc;

    Player* p = pc.search("jogadornaoexiste");

    EXPECT_EQ(p, nullptr);
}