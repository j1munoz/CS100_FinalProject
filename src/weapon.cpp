#include "../header/weapon.hpp"
Weapon::Weapon(): Item(), critChance(0) {}

Weapon::Weapon(string name, string rarity, float critChance, float dmg, int price)
    :Item(name, rarity, dmg, price), critChance(critChance) {}

bool Weapon::rollCritChance() {
    // Implement code here

    return false;
}

float Weapon::getDmg() {
    // Implement code here

    return 0;
}

void Weapon::displayDescription() {
    // Implement code here
}