#include "../header/spell.hpp"

Spell::Spell():Item(), manaCost(0), castTime(0) {}

Spell::Spell(const string& name, const string& rarity, const float& dmg, const int manaCost, const int castTime, const int price, const int index)
    :Item(name, rarity, dmg, price), manaCost(manaCost), castTime(castTime), monsterIndex(index) {}

int Spell::getManaCost() const {
    return this->manaCost;
}

int Spell::getCastTime() const {
    return this->castTime;
}

int Spell::getMonsterIndex() const {
    return this->monsterIndex;
}