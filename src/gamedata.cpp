#include "../header/gamedata.hpp"

GameData::GameData(): levelCount(levelCount) {

}

GameData::GameData(int levelCount) {}

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