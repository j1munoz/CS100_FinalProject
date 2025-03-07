#include "gtest/gtest.h"
#include "../header/player.hpp"

TEST(PlayerTests, isPlayerAlive) {
    Player player;

    EXPECT_TRUE(player.isAlive());
}