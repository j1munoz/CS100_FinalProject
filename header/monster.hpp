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
        Monster(const string& name, const float& health, const int& mana, const int& defense, const int& lifetime, const int& maxLifetime, const Weapon& currentWeapon)
        : Character(name, health, mana, defense, currentWeapon), lifetime(lifetime), maxLifetime(maxLifetime) {}

        int getLifetime() const;                // Return lifetime
        void setLifetime(const int&);           // Sets the lifetime

        int getMaxLifetime() const;             // Return max lifetime
        void setMaxLifetime(const int&);        // Sets the max lifetime
        
        // We must override these functions from Abstract class
        float useAttack() const override;       // If the entity can't perform this, return 0
};

#endif /* MONSTER_HPP */