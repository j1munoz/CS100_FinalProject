#include "gtest/gtest.h"
#include "../header/spell.hpp"

TEST(SpellTests, spellDefaultConstructor) {
    Spell spell;

    EXPECT_EQ(spell.getCastTime(), 0);
    EXPECT_EQ(spell.getDmg(), 0);
    EXPECT_EQ(spell.getManaCost(), 0);
    EXPECT_EQ(spell.getName(), "");
    EXPECT_EQ(spell.getPrice(), 0);
    EXPECT_EQ(spell.getRarity(), "Common");
}

TEST(SpellTests, spellOverloadConstructor) {
    Spell spell("Lighting Wave", "Rare", 60, 20, 3, 150);

    EXPECT_EQ(spell.getCastTime(), 3);
    EXPECT_EQ(spell.getDmg(), 60);
    EXPECT_EQ(spell.getManaCost(), 20);
    EXPECT_EQ(spell.getName(), "Lighting Wave");
    EXPECT_EQ(spell.getPrice(), 150);
    EXPECT_EQ(spell.getRarity(), "Rare");
}