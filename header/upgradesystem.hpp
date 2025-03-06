#ifndef UPGRADE_SYSTEM_HPP
#define UPGRADE_SYSTEM_HPP

#include "character.hpp"
#include "player.hpp"

class UpgradeSystem : public Character {
    public:
    // Skill Point Upgrades
    void increaseHealth(Player& user, int amount);     // Increase maximum health
    void increasePhysAtk(Player& user, int amount);
    void inncreaseMgAtk(Player& user, int amount);
    void increaseDef(Player& user, int amount);          // Increase defense
    void increaseMana(Player& user, int amount);
};

#endif /* UPGRADE_SYSTEM_HPP */