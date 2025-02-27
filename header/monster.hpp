#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "character.hpp"
#include <vector>
using namespace std;

class Monster : public Character {
	private:
		int lifetime;   // Lifetime of the summoned monster
	public:
        // Implement default and overloaded constructor
        Monster();
        Monster(string name, float health, int mana, int defense, int lifetime)
        : Character(name, health, mana, defense), lifetime(lifetime) {}

        int getLifetime();      // Return lifetime
        void setLifetime(int);   // Sets the lifetime
        
        // We must override these functions from Abstract class
        float useAttack() override;  // If the entity can't perform this, return 0
        float useSpell() override;   // If the entity can't perform this, return 0
};

#endif /* MONSTER_HPP */