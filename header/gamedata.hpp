#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include <vector>
#include "weapon.hpp"
#include "spell.hpp"
#include "enemy.hpp"
#include "monster.hpp"
#include "player.hpp"
#include "shop.hpp"

class GameData {
	private:
	std::vector<Weapon> weaponList;
        std::vector<Spell> spellList;
        std::vector<Enemy> enemyList;
        std::vector<Monster> monsterList;

        Shop theShop;
        Player user;
        int levelCount;
	public:
        // Implement default and overloaded constructor

        void fillEnemyList();
        void fillMonsterList();
        int getLvlCount();
        void setLvlCount(int);
        Shop getShop();
        Player getPlayer();
        void setPlayer(Player);
};

#endif /* GAMEDATA_HPP */