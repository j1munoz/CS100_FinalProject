#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "item.hpp"

class Weapon : public Item {
private:
        float critChance;      // Percentage of success crit
        bool rollCritChance(); // Returns if crit chance was successful

public:
        // Implement default and overloaded constructor
        Weapon();
        Weapon(string name, string rarity, float critChance, float dmg, int price);

        float getCritChance() const;
        float getDmg() override;
};

#endif /* WEAPON_HPP */