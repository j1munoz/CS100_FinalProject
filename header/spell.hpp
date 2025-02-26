#ifndef SPELL_HPP
#define SPELL_HPP

#include "item.hpp"

class Spell : public Item {
private:
	int manaCost; // Cost of mana
	int castTime; // # of turns required to cast

public:
	// Implement default and overloaded constructor
	Spell();
	Spell(string name, string rarity, float dmg, int manaCost, int castTime, int price);

	int getManaCost(); // Returns mana cost
	int getCastTime(); // Returns cast time

	void displayDescription() override; // Displays all stats of an item
};

#endif /* SPELL_HPP */