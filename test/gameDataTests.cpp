#include "gtest/gtest.h"
#include "../header/gamedata.hpp"

TEST(GameDataTests, GameDataDefaultConstructor) {
    GameData data;

    EXPECT_NO_THROW(GameData moreData);
    EXPECT_EQ(data.getLvlCount(), 1);
}