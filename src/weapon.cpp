#include "../header/weapon.hpp"
#include <ctime>
Weapon::Weapon(): Item(), critChance(0) {}

Weapon::Weapon(string name, string rarity, float critChance, float dmg, int price)
    :Item(name, rarity, dmg, price), critChance(critChance) {}

float Weapon::getCritChance() const {
    return critChance;
}

bool Weapon::rollCritChance() {
    srand((time(0)));

    float roll = (rand() % 100);
    
    if (roll < getCritChance()) {  // If the roll is less to the crit chance it counts it as critical (its exclusive cause 0 is included in the chance)
        return true;  // Critical hit
    } else {
        return false; // Normal hit
    }
}

float Weapon::getDmg() {
    return Item::getDmg();
}