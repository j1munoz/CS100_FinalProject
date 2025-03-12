#include "gtest/gtest.h"
#include "../header/player.hpp"
#include "../header/upgradesystem.hpp"

TEST(UpgradeSystemTests, upgradeHealth) {
    Player player;
    UpgradeSystem upgrade;

    upgrade.increaseHealth(player, player.getTotalHealth() + 5);

    EXPECT_EQ(player.getTotalHealth(), 105);
}

TEST(UpgradeSystemTests, upgradeDefense) {
    Player player;
    UpgradeSystem upgrade;

    upgrade.increaseDef(player, player.getDefense() + 1);

    EXPECT_EQ(player.getDefense(), 11);
}

TEST(UpgradeSystemTests, upgradeMana) {
    Player player;
    UpgradeSystem upgrade;

    upgrade.increaseMana(player, player.getMaxMana() + 5);

    EXPECT_EQ(player.getMaxMana(), 105);
}

TEST(UpgradeSystemTests, upgradeMonsterCount) {
    Player player;
    UpgradeSystem upgrade;

    upgrade.increaseHealth(player, player.getMaxMonCount() + 1);

    EXPECT_EQ(player.getMaxMonCount(), 3);
}