#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "character.hpp"
#include <vector>
using namespace std;

class Enemy : public Character {
	private:
        float dropChance;

        // Private Helper Function
        float rollDrop() const;
	public:
        // Implement default and overloaded constructor
        Enemy();
        Enemy(const string& name, const float& health, const int& mana, const int& defense, const Weapon& currentWeapon, const float& dropChance)
        : Character(name, health, mana, defense, currentWeapon), dropChance(dropChance) {}

        bool dropItem() const;    // Returns the dropped loot (if applicable)
        
        // We must override these functions from Abstract class
        float useAttack() const override;  // If the entity can't perform this, return 0
};

#endif /* ENEMY_HPP */