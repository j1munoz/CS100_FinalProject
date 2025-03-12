#include "gtest/gtest.h"
#include "../header/weapon.hpp"

TEST(WeaponTests, weaponDefaultConstructor) {
    Weapon weapon;

    EXPECT_EQ(weapon.getName(), "");
    EXPECT_EQ(weapon.getRarity(), "Common");
    EXPECT_EQ(weapon.getDmg(), 0);
    EXPECT_EQ(weapon.getPrice(), 0);
    EXPECT_FLOAT_EQ(weapon.getCritChance(), 0);
}

TEST(WeaponTests, weaponOverloadConstructor) {
    Weapon weapon("Hammer of Giants", "Legendary", 30, 65, 500);

    EXPECT_EQ(weapon.getName(), "Hammer of Giants");
    EXPECT_EQ(weapon.getRarity(), "Legendary");
    EXPECT_EQ(weapon.getDmg(), 65);
    EXPECT_EQ(weapon.getPrice(), 500);
    EXPECT_FLOAT_EQ(weapon.getCritChance(), 30);
}

TEST(WeaponTests, weaponNoCrit) {
    Weapon weapon("Hammer of Giants", "Legendary", 0, 65, 500);

    EXPECT_FALSE(weapon.rollCritChance());
}

TEST(WeaponTests, weaponHitCrit) {
    Weapon weapon("Hammer of Giants", "Legendary", 100, 65, 500);

    EXPECT_TRUE(weapon.rollCritChance());
}