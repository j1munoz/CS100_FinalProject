#include "gtest/gtest.h"
#include "../header/enemy.hpp"

TEST(EnemyTests, enemyDefaultConstructor) {
    Enemy enemy;

    EXPECT_EQ(enemy.getCurrentWeapon().getName(), "Nothing");
    EXPECT_EQ(enemy.getName(), "Enigma");
    EXPECT_TRUE(enemy.isAlive());
    EXPECT_EQ(enemy.getDefense(), 999);
    EXPECT_EQ(enemy.getHealth(), 999);
    EXPECT_EQ(enemy.getMana(), 999);
}

TEST(EnemyTests, enemyOverloadedConstructor) {
    Enemy enemy("Training Dummy", 50, 0, 5, Weapon("Stick Arm", "Common", 1, 11, 0), 75);

    EXPECT_EQ(enemy.getCurrentWeapon().getName(), "Stick Arm");
    EXPECT_EQ(enemy.getName(), "Training Dummy");
    EXPECT_TRUE(enemy.isAlive());
    EXPECT_EQ(enemy.getDefense(), 5);
    EXPECT_EQ(enemy.getHealth(), 50);
    EXPECT_EQ(enemy.getMana(), 0);
}

TEST(EnemyTests, enemyAttacks) {
    Enemy enemy;

    EXPECT_GT(enemy.useAttack(), 0);
}

TEST(EnemyTests, enemyDoNotDrop) {
    Enemy enemy("Training Dummy", 50, 0, 5, Weapon("Stick Arm", "Common", 1, 11, 0), 0);

    EXPECT_FALSE(enemy.dropItem());
}

TEST(EnemyTests, enemyExpectDrop) {
    Enemy enemy("Training Dummy", 50, 0, 5, Weapon("Stick Arm", "Common", 1, 11, 0), 100);

    EXPECT_TRUE(enemy.dropItem());
}
