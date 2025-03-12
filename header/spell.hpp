#ifndef SPELL_HPP
#define SPELL_HPP

#include "item.hpp"

class Spell : public Item {
private:
	int manaCost; // Cost of mana
	int castTime; // # of turns required to cast
	int monsterIndex; // For summoning spells

public:
	// Implement default and overloaded constructor
	Spell();
	Spell(const string& name, const string& rarity, const float& dmg, const int manaCost, const int castTime, const int price, const int index);

	int getManaCost() const; // Returns mana cost
	int getCastTime() const; // Returns cast time
	int getMonsterIndex() const; // Return index for monster
};

#endif /* SPELL_HPP */