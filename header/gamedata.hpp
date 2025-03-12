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
        ~GameData();

        int getLvlCount() const;                        // Get the level count
        void setLvlCount(const int& level);             // Set the level count
        Shop& getShop();                                // Get the shop
        Player& getPlayer();                            // Get the player
        void setPlayer(const Player&);                  // Set the player
        Monster getMonster(const int&) const;           // Get a monster
  
        std::vector<Enemy>& getEnemyList();
        std::vector<Item*> getBothLists();
        void clearBothLists();
};

#endif /* GAMEDATA_HPP */