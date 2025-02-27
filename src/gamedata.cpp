#include "../header/gamedata.hpp"

GameData::GameData() {

        //Format is as follows for hardcoding enemies:
        //| Name | Health | Mana | Defense |
    enemyList = {
        Enemy("Peasent", 10, 0, 2),
        Enemy("Adventurer", 30, 10, 10),
        Enemy("Knight", 80, 25, 30)
    };

        //Format is as follows for hardcoding monsters:
        //| Name | Health | Mana | Defense | Lifetime |
    monsterList = {
        Monster("Slime", 10, 0, 2, 5),
        Monster("Skeleton", 30, 10, 10, 5),
        Monster("Golem", 80, 25, 30, 5)
    };

}

int GameData::getLvlCount() {
    return this->levelCount;
}

void GameData::setLvlCount(int amount) {
    this->levelCount = amount;
}

Shop GameData::getShop() {
    return this->theShop;
}

Player GameData::getPlayer() {
    return this->user;
}

void GameData::setPlayer(Player user) {
    this->user = user;
}