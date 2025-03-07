#include "../header/gamedata.hpp"

GameData::GameData(): levelCount(1) {
    weaponList = {
        // | Name | Rarity | Crit Chance | Damage | Sell Price |
        Weapon("Sword", "Common", 1, 15, 50),
        Weapon("Pitchfork", "Common", 1, 15, 50),
        Weapon("Goo Spike", "Common", 1, 15, 50),
        Weapon("Berserker Axe", "Uncommon", 2, 25, 100),
        Weapon("Scimitar", "Uncommon", 2, 25, 100),
        Weapon("Bone Knife", "Uncommon", 2, 25, 100),
        Weapon("Vanguard Claymore", "Rare", 3, 40, 150),
        Weapon("Crusader Hammer", "Rare", 3, 40, 200),
        Weapon("Sandstone Gauntlets", "Rare", 3, 40, 200),
        Weapon("Hammer of Giants", "Legendary", 5, 75, 500)
        
    };
    spellList = {
        // | Name | Rarity | Damage | Mana Cost | Cast Time | Sell Price |
        Spell("Fireball", "Common", 30, 10, 1, 50),
        Spell("Ice Trap", "Uncommon", 45, 15, 2, 100),
        Spell("Lighting Wave", "Rare", 60, 20, 3, 150),
        Spell("Meteor Shower", "Legendary", 100, 50, 5, 600)
    };

    enemyList = {
        //Format is as follows for hardcoding enemies:
        //| Name | Health | Mana | Defense | Weapon |
        Enemy("Peasent", 10, 0, 2, Weapon("Pitchfork", "Common", 1, 15, 50)),
        Enemy("Adventurer", 30, 10, 10, Weapon("Scimitar", "Uncommon", 2, 25, 100)),
        Enemy("Knight", 80, 25, 30, Weapon("Crusader Hammer", "Rare", 3, 40, 200))
    };
  
    monsterList = {
        //Format is as follows for hardcoding monsters:
        //| Name | Health | Mana | Defense | Lifetime | Weapon |
        Monster("Slime", 10, 0, 2, 5, Weapon("Goo Spike", "Common", 1, 15, 50)),
        Monster("Skeleton", 30, 10, 10, 5, Weapon("Bone Knife", "Uncommon", 2, 25, 100)),
        Monster("Golem", 80, 25, 30, 5, Weapon("Sandstone Gauntlets", "Rare", 3, 40, 200))
    };

    theShop.fillShop(weaponList);
}

int GameData::getLvlCount() {
    return this->levelCount;
}

void GameData::setLvlCount(int amount) {
    this->levelCount = amount;
}

Shop& GameData::getShop() {
    return this->theShop;
}

Player& GameData::getPlayer() {
    return this->user;
}

void GameData::setPlayer(Player user) {
    this->user = user;
}