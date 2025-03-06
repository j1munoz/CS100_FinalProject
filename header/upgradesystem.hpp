#ifndef UPGRADE_SYSTEM_HPP
#define UPGRADE_SYSTEM_HPP

#include "character.hpp"

class UpgradeSystem {
    public:
    // Skill Point Upgrades
    void increaseHealth(Character& user, int amount);     // Increase maximum health
    void increasePhysAtk(Character& user, int amount);
    void inncreaseMgAtk(Character& user, int amount);
    void increaseDef(Character& user, int amount);          // Increase defense
    void increaseMana(Character& user, int amount);
};

#endif /* UPGRADE_SYSTEM_HPP */