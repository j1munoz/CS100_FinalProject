#include "gtest/gtest.h"
#include "../header/monster.hpp"

TEST(MonsterTests, MonsterDefaultConstructor) {
    Monster monster;

    EXPECT_EQ(monster.getName(), "Enigma");
    EXPECT_EQ(monster.getCurrentWeapon().getName(), "Nothing");
    EXPECT_EQ(monster.getDefense(), 999);
    EXPECT_EQ(monster.getTotalHealth(), 999);
    EXPECT_EQ(monster.getMana(), 999);
    EXPECT_EQ(monster.getMaxLifetime(), 0);
    EXPECT_EQ(monster.getLifetime(), 999);
}

TEST(MonsterTests, MonsterOverloadConstructor) {
    Monster monster("Slime", 15, 0, 2, 0, 2, Weapon("Goo Spike", "Common", 10, 15, 50));

    EXPECT_EQ(monster.getName(), "Slime");
    EXPECT_EQ(monster.getCurrentWeapon().getName(), "Goo Spike");
    EXPECT_EQ(monster.getDefense(), 2);
    EXPECT_EQ(monster.getTotalHealth(), 15);
    EXPECT_EQ(monster.getMana(), 0);
    EXPECT_EQ(monster.getMaxLifetime(), 2);
    EXPECT_EQ(monster.getLifetime(), 0);
}

TEST(MonsterTests, MonsterAttacks) {
    Monster monster;

    EXPECT_GT(monster.useAttack(), 0);
}