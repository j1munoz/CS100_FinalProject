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
        std::vector<Item*> bothItemLists;
        std::vector<Enemy> enemyList;
        std::vector<Monster> monsterList;

        Shop theShop;
        Player user;
        int levelCount;
public:
        // Implement default and overloaded constructor
        GameData();

        int getLvlCount();
        void setLvlCount(int);
        std::vector<Item*> getBothLists();
        void clearBothLists();
        Shop& getShop();
        Player& getPlayer();
        void setPlayer(Player);

        Monster getMonster(const int);
};

#endif /* GAMEDATA_HPP */