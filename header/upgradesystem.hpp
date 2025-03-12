#ifndef UPGRADE_SYSTEM_HPP
#define UPGRADE_SYSTEM_HPP

#include "player.hpp"

class UpgradeSystem {
    public:
    // Skill Point Upgrades
    void increaseHealth(Player& user, const int& amount) const;       // Increase maximum health
    void increaseDef(Player& user, const int& amount) const;          // Increase defense
    void increaseMana(Player& user, const int& amount) const;         // Increase mana
    void increaseMonsterCount(Player& user, const int& amount) const; // Increase monster count
};

#endif /* UPGRADE_SYSTEM_HPP */