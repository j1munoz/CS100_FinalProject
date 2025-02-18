#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "character.hpp"
#include <vector>
using namespace std;

class Enemy : public Character {
	private:
		Item loot;
                vector<Enemy> enemyList;
        float dropChance;

        // Private Helper Function
        float rollDrop();
	public:
        // Implement default and overloaded constructor
        Enemy();
        Enemy(string name, float health, int mana, int defense)
        : Character(name, health, mana, defense) {}

        vector<Enemy>& getEnemyList();
        string getName();
        Item dropItem();    // Returns the dropped loot (if applicable)
        
        // We must override these functions from Abstract class
        float useAttack() override;  // If the entity can't perform this, return 0
        float useSpell() override;   // If the entity can't perform this, return 0
};

#endif /* ENEMY_HPP */