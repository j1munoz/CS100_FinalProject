#include "../header/weapon.hpp"
Weapon::Weapon(): Item(), critChance(0) {}

Weapon::Weapon(string name, string rarity, float critChance, float dmg, int price)
    :Item(name, rarity, dmg, price), critChance(critChance) {}

float Weapon::getCritChance() const {
    return critChance;
}
bool Weapon::rollCritChance() {
    // Implement code here
    return false;
}

float Weapon::getDmg() {
    return Item::getDmg();
}