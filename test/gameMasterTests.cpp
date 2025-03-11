#include "gtest/gtest.h"
#include "../header/gamemaster.hpp"

TEST(GameMasterTests, GameMasterBattlePhysical) {
    GameData data;
    Player player = data.getPlayer();
    Enemy enemy("Training Dummy", 50, 0, 5, Weapon("Stick Arm", "Common", 1, 11, 0), 75);

    // Calculate damage done
    float dmgValue = player.useAttack() - enemy.getDefense();
    float dmgDone = (dmgValue > 0) ? dmgValue : 0;

    float healthValue = enemy.getHealth() - dmgDone;
    float remainingHealth = (healthValue > 0) ? healthValue : 0;

    enemy.setHealth(remainingHealth);

    EXPECT_LE(enemy.getHealth(), enemy.getTotalHealth());
}

TEST(GameMasterTests, GameMasterBattleSpell) {
    GameData data;
    Player player = data.getPlayer();
    Enemy enemy("Training Dummy", 50, 0, 5, Weapon("Stick Arm", "Common", 1, 11, 0), 75);
    
    player.setCastingStatus(false);
                
    // Calculate damage done
    float dmgValue = player.getSpell(0).getDmg() - enemy.getDefense();
    float dmgDone = (dmgValue > 0) ? dmgValue : 0;

    float healthValue = enemy.getHealth() - dmgDone;
    float remainingHealth = (healthValue > 0) ? healthValue : 0;

    enemy.setHealth(remainingHealth);

    EXPECT_EQ(enemy.getHealth(), enemy.getTotalHealth() - 35);
}