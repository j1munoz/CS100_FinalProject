#include "../header/weapon.hpp"
#include <ctime>
Weapon::Weapon(): Item(), critChance(0) {}

Weapon::Weapon(const string& name, const string& rarity, const float& critChance, const float& dmg, const int& price)
    :Item(name, rarity, dmg, price), critChance(critChance) {}

float Weapon::getCritChance() const {
    return critChance;
}

bool Weapon::rollCritChance() const {
    srand((time(0)));

    float roll = (rand() % 100);
    
    return roll < getCritChance();
}

float Weapon::getDmg() const {
    return Item::getDmg();
}