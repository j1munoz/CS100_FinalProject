#include "../header/gamedata.hpp"

GameData::GameData(): levelCount(1) {
    weaponList = {
        // | Name | Rarity | Crit Chance | Damage | Sell Price |
        Weapon("Sword", "Common", 1, 15, 50),
        Weapon("Berserker Axe", "Uncommon", 2, 25, 100),
        Weapon("Vanguard Claymore", "Rare", 3, 40, 150),
        Weapon("Hammer of Giants", "Legendary", 5, 75, 500)
    };
    spellList = {
        // | Name | Rarity | Damage | Mana Cost | Cast Time | Sell Price |
        Spell("Fireball", "Common", 30, 10, 1, 50),
        Spell("Ice Trap", "Uncommon", 45, 15, 2, 100),
        Spell("Lighting Wave", "Rare", 60, 20, 3, 150),
        Spell("Meteor Shower", "Legendary", 100, 50, 5, 600)
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