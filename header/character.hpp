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
        Character(string name, float totalHealth, int mana, int defense, Weapon currentWeapon);
        
		bool isAlive();     // Tests if entity is alive

        // NOTE: These functions are vitual because each attack
        // will be implemented slighty differently among entities
        virtual float useAttack() = 0;  // Attack function

        string getName();
        void setMana(int);              // Set mana cost
        int getMana();                  // Return mana
        int getMaxMana();               // Return max mana
        void setHealth(float);          // Set health
        float getHealth();              // Return health
        void setDefense(int);           // Set defense
        int getDefense();               // Return defense
        void setTotalHealth(float);     // Set max health
        float getTotalHealth();         // Get max heatlh
        void displayHealth();           // Display health bar + mana
};

#endif /* CHARACTER_HPP */