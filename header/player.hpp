#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "character.hpp"
#include "monster.hpp"

class Player : public Character {
	private:
		int currency;
                int skillPoints;
                int experience;
                std::vector<Weapon> inventory;
                int monsterCount;
                int maxMonsterCount;
                bool isCasting;
                std::vector<Spell> spellBook;   // List of spells to use
                std::vector<Monster> summonedMon;
	public:
        // Implement default and overloaded constructor
        Player();

        // Battle Functions
        void equipItem(const int&);               // Given an index, return Item in inventory
        void showInventory() const;               // Display items in inventory
        void addItem(const Weapon&);              // Add item to inventory
        void removeItem(const int&);              // Removes item from inventory
        void sellItem(const int&);                // Sell item for price (pass index)
        void addSpell(const Spell&);              // Add spell to spellbook
        void showSpells() const;                  // Display spells in spellbook
        bool getCastingStatus() const;            // Return if casting
        void setCastingStatus(const bool&);       // Set casting status
        int getMonCount() const;                  // Get how many monsters are summoned
        void setMonCount(const int&);             // Set monster count
        int getMaxMonCount() const;               // Get maximum monsters
        void setMaxMonCount(const int&);          // Set maximum monsters
        int getInventorySize() const;             // Get the size of the current inventory
        int getSpellBookSize() const;             // Get the size of the current spell book
        void displayMana() const;                 // Display mana
        Weapon getWeapon(const int& index);       // Get a weapon
        Spell getSpell(const int& index);         // Get a spell
        std::vector<Monster>& getSummonedMon();   // Get summoned monsters
        void setExperience(const int& exp);       // Set experience points
        int getExperience() const;                // Get experience points
        void setSkillPoints(const int& points);   // Set skill points
        int getSkillPoints() const;               // Get skill points

        // Shop Functions
        int getCurrency() const;                  // Return money
        void setCurrency(const int&);             // Set currency
        
        // We must override these functions from Abstract class
        float useAttack() const override;  // If the entity can't perform this, return 0
};

#endif /* PLAYER_HPP */
