#include "../header/spell.hpp"

Spell::Spell():Item(), manaCost(0), castTime(0) {}

Spell::Spell(string name, string rarity, float dmg, int manaCost, int castTime, int price)
    :Item(name, rarity, dmg, price), manaCost(manaCost), castTime(castTime) {}

int Spell::getManaCost() {
    return this->manaCost;
}

int Spell::getCastTime() {
    return this->castTime;
}

void Spell::displayDescription() {
    // Implement code here
}