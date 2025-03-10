#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "character.hpp"
#include <vector>
using namespace std;

class Monster : public Character {
        private:
	int lifetime;     // Lifetime of the summoned monster
        int maxLifetime;  // Maximum lifetime of a summoned monster
        public:
        // Implement default and overloaded constructor
        Monster();
        Monster(string name, float health, int mana, int defense, int lifetime, int maxLifetime, Weapon currentWeapon)
        : Character(name, health, mana, defense, currentWeapon), lifetime(lifetime), maxLifetime(maxLifetime) {}

        int getLifetime();        // Return lifetime
        void setLifetime(int);    // Sets the lifetime

        int getMaxLifetime();     // Return max lifetime
        void setMaxLifetime(int); // Sets the max lifetime
        
        // We must override these functions from Abstract class
        float useAttack() override;  // If the entity can't perform this, return 0
};

#endif /* MONSTER_HPP */