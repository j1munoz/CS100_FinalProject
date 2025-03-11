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

TEST(WeaponTests, weaponOerloadConstructor) {
    Weapon weapon("Hammer of Giants", "Legendary", 5, 75, 500);

    EXPECT_EQ(weapon.getName(), "Hammer of Giants");
    EXPECT_EQ(weapon.getRarity(), "Legendary");
    EXPECT_EQ(weapon.getDmg(), 75);
    EXPECT_EQ(weapon.getPrice(), 500);
    EXPECT_FLOAT_EQ(weapon.getCritChance(), 5);
}

TEST(WeaponTests, weaponNoCrit) {
    Weapon weapon("Hammer of Giants", "Legendary", 0, 75, 500);

    EXPECT_FALSE(weapon.rollCritChance());
}

TEST(WeaponTests, weaponHitCrit) {
    Weapon weapon("Hammer of Giants", "Legendary", 100, 75, 500);

    EXPECT_TRUE(weapon.rollCritChance());
}