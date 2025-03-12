#include "gtest/gtest.h"
#include "../header/player.hpp"
#include "../header/weapon.hpp"
#include "../header/spell.hpp"

TEST(PlayerTests, playerDefaultConstructor) {
    Player player;

    EXPECT_EQ(player.getCurrency(), 300);
    EXPECT_EQ(player.getMaxMonCount(), 3);
    EXPECT_EQ(player.getMonCount(), 0);
    EXPECT_EQ(player.getMana(), 100);
    EXPECT_EQ(player.getMaxMana(), 100);
    EXPECT_FALSE(player.getCastingStatus());
    EXPECT_EQ(player.getName(), "Villain");
    EXPECT_EQ(player.getHealth(), 100);
    EXPECT_EQ(player.getTotalHealth(), 100);
    EXPECT_EQ(player.getDefense(), 10);
    EXPECT_EQ(player.getCurrentWeapon().getName(), "Flimsy Sword");
    EXPECT_EQ(player.getSpellBookSize(), 2);
    EXPECT_TRUE(player.isAlive());
}

TEST(PlayerTests, playerAddItem) {
    Player player;
    Weapon weapon;

    player.addItem(Weapon("Scimitar", "Uncommon", 2, 25, 100));

    EXPECT_EQ(player.getWeapon(0).getName(), "Scimitar");
}

TEST(PlayerTests, playerEquipItem) {
    Player player;

    player.addItem(Weapon("Scimitar", "Uncommon", 2, 25, 100));
    player.equipItem(0);

    EXPECT_EQ(player.getCurrentWeapon().getName(), "Scimitar");
}

TEST(PlayerTests, playerRemoveItem) {
    Player player;

    player.addItem(Weapon("Scimitar", "Uncommon", 2, 25, 100));
    player.removeItem(0);

    EXPECT_EQ(player.getInventorySize(), 0);
}

TEST(PlayerTests, playerAddSpell) {
    Player player;

    player.addSpell(Spell("Fireball", "Common", 30, 10, 1, 50, -1));

    EXPECT_EQ(player.getSpell(2).getName(), "Fireball");
}

TEST(PlayerTests, playerCurrency) {
    Player player;

    player.setCurrency(500);

    EXPECT_EQ(player.getCurrency(), 500);
}

TEST(PlayerTests, playerAttack) {
    Player player;
    float damageAmount = player.useAttack();

    EXPECT_GT(damageAmount, 0);
}
