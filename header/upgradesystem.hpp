#ifndef UPGRADE_SYSTEM_HPP
#define UPGRADE_SYSTEM_HPP

#include "player.hpp"

class UpgradeSystem {
    public:
    // Skill Point Upgrades
    void increaseHealth(Player& user, const int& amount);       // Increase maximum health
    void increaseDef(Player& user, const int& amount);          // Increase defense
    void increaseMana(Player& user, const int& amount);         // Increase mana
    void increaseMonsterCount(Player& user, const int& amount); // Increase monster count
};

#endif /* UPGRADE_SYSTEM_HPP */