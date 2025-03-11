#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include "spell.hpp"
#include "weapon.hpp"

using std::string;

class Character {
	protected:
		string name;                // Name of Entity
        float totalHealth;          // Maximum Health
        float currentHealth;        // Current Health
        int mana;                   // Mana Points for spells
        int maxMana;                // Max Mana Points
        int defense;                // Defense stat
        Weapon currentWeapon;       // Current equipped item

	public:
        // Implement default and overloaded constructor
        Character();
        Character(const string& name, const float& totalHealth, const int& mana, const int& defense, const Weapon& currentWeapon);
        
		bool isAlive() const;     // Tests if entity is alive

        // NOTE: These functions are vitual because each attack
        // will be implemented slighty differently among entities
        virtual float useAttack() const = 0;  // Attack function

        string getName() const;
        void setMana(const int&);              // Set mana cost
        void setMaxMana(const int&);           // Set max mana
        int getMana() const;                   // Return mana
        int getMaxMana() const;                // Return max mana
        void setHealth(const float&);          // Set health
        float getHealth() const;               // Return health
        void setDefense(const int&);           // Set defense
        int getDefense() const;                // Return defense
        void setTotalHealth(const float&);     // Set max health
        float getTotalHealth() const;          // Get max heatlh
        void displayHealth() const;            // Display health bar + mana
        Weapon getCurrentWeapon() const;       // Return currently held weapon
};

#endif /* CHARACTER_HPP */