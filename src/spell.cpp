#include "../header/spell.hpp"

Spell::Spell():Item(), manaCost(0), castTime(0) {}

Spell::Spell(const string& name, const string& rarity, const float& dmg, const int& manaCost, const int& castTime, const int& price)
    :Item(name, rarity, dmg, price), manaCost(manaCost), castTime(castTime) {}

int Spell::getManaCost() const {
    return this->manaCost;
}

int Spell::getCastTime() const {
    return this->castTime;
}