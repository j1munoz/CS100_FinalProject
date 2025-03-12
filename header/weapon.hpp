#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "item.hpp"

class Weapon : public Item {
private:
        float critChance;      // Percentage of success crit

public:
        // Implement default and overloaded constructor
        Weapon();
        Weapon(const string& name, const string& rarity, const float& critChance, const float& dmg, const int& price);
        bool rollCritChance() const; // Returns if crit chance was successful
        float getCritChance() const;
        float getDmg() const override;
};

#endif /* WEAPON_HPP */