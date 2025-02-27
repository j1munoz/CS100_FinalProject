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

        Weapon currentWeapon;           // Current equipped item
        std::vector<Spell> spellBook;   // List of spells to use
	public:
        // Implement default and overloaded constructor
        Character();
        Character(string name, float totalHealth, int mana, int defense)
        : name(name), totalHealth(totalHealth), currentHealth(totalHealth), mana(mana), maxMana(mana), defense(defense) {}
        
		bool isAlive();     // Tests if entity is alive

        // NOTE: These functions are vitual because each attack
        // will be implemented slighty differently among entities
        virtual float useAttack() = 0;  // Attack function
        virtual float useSpell() = 0;   // Magic attack function

        int getMana();                  // Return mana
        void setMana(int);              // Set mana cost
        int getMaxMana();               // Return max mana
        void displayHealth();           // Display health bar + mana
        float getHealth();              // Return health
        void setHealth(float);          // Set health
        float getTotalHealth();         // Get max heatlh
        void setTotalHealth(float);     // Set max health
        int getDefense();               // Return defense
        void setDefense(int);           // Set defense
};

#endif /* CHARACTER_HPP */