#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "character.hpp"

class Player : public Character {
	private:
		int currency;
                int skillPoints;
                std::vector<Weapon> inventory;
                int monsterCount;
                int maxMonsterCount;
                bool isCasting;
                std::vector<Spell> spellBook;   // List of spells to use
	public:
        // Implement default and overloaded constructor
        Player();

        // Battle Functions
        void equipItem(int);            // Given an index, return Item in inventory
        void showInventory();           // Display items in inventory
        void addItem(Weapon);           // Add item to inventory
        void sellItem(int);             // Sell item for price (pass index)
        void addSpell(Spell);           // Add spell to spellbook
        void showSpells();              // Display spells in spellbook
        bool getCastingStatus();        // Return if casting
        void setCastingStatus(bool);    // Set casting status
        int getMonCount();              // Get how many monsters are summoned
        void setMonCount(int);          // Set monster count
        int getMaxMonCount();           // Get maximum monsters
        void setMaxMonCount(int);       // Set maximum monsters
        int getInventorySize() const;   // Get the size of the current inventory
        int getSpellBookSize() const;   // Get the size of the current spell book
        Weapon getWeapon(const int& index);       // Get a weapon
        Spell getSpell(const int& index);         // Get a spell

        // Shop Functions
        int getCurrency();              // Return money
        void setCurrency(int);          // Set currency
        
        // We must override these functions from Abstract class
        float useAttack() override;  // If the entity can't perform this, return 0
};

#endif /* PLAYER_HPP */
