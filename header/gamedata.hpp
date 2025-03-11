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
        std::vector<Item> weaponList;
        std::vector<Item> spellList;
        std::vector<Enemy> enemyList;
        std::vector<Monster> monsterList;

        Shop theShop;
        Player user;
        int levelCount;
public:
        // Implement default and overloaded constructor
        GameData();

        int getLvlCount() const;                        // Get the level count
        void setLvlCount(const int& level);             // Set the level count
        Shop& getShop();                                // Get the shop
        Player& getPlayer();                            // Get the player
        void setPlayer(const Player&);                  // Set the player
        Monster getMonster(const int&) const;           // Get a monster
};

#endif /* GAMEDATA_HPP */