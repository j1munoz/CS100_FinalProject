#include "../header/gamedata.hpp"

GameData::GameData(): levelCount(1) {
    weaponList = {
        // | Name | Rarity | Crit Chance | Damage | Sell Price |
        Weapon("Sword", "Common", 10, 15, 50),
        Weapon("Pitchfork", "Common", 10, 15, 50),
        Weapon("Goo Spike", "Common", 10, 15, 50),
        Weapon("Berserker Axe", "Uncommon", 20, 25, 100),
        Weapon("Scimitar", "Uncommon", 20, 25, 100),
        Weapon("Bone Knife", "Uncommon", 20, 25, 100),
        Weapon("Vanguard Claymore", "Rare", 30, 40, 150),
        Weapon("Crusader Hammer", "Rare", 30, 40, 200),
        Weapon("Sandstone Gauntlets", "Rare", 30, 40, 200),
        Weapon("Hammer of Giants", "Legendary", 50, 75, 500)
        
    };
    spellList = {
        // | Name | Rarity | Damage | Mana Cost | Cast Time | Sell Price |
        Spell("Summon Slime", "Monster", 0, 40, 0, 0),
        Spell("Summon Skeleton", "Monster", 0, 65, 0, 1),
        Spell("Summon Golem", "Monster", 0, 80, 0, 2),
        Spell("Fireball", "Common", 30, 10, 1, 50),
        Spell("Ice Trap", "Uncommon", 45, 15, 2, 100),
        Spell("Lighting Wave", "Rare", 60, 20, 3, 150),
        Spell("Meteor Shower", "Legendary", 100, 50, 5, 600)
    };

    enemyList = {
        //Format is as follows for hardcoding enemies:
        //| Name | Health | Mana | Defense | Weapon | Drop Chance
        Enemy("Peasent", 10, 0, 2, Weapon("Pitchfork", "Common", 10, 15, 50), 50),
        Enemy("Adventurer", 30, 10, 10, Weapon("Scimitar", "Uncommon", 20, 25, 100), 25),
        Enemy("Knight", 80, 25, 30, Weapon("Crusader Hammer", "Rare", 15, 40, 200), 15)
    };
  
    monsterList = {
        //Format is as follows for hardcoding monsters:
        //| Name | Health | Mana | Defense | Lifetime | Max Lifetime | Weapon |
        Monster("Slime", 15, 0, 2, 0, 2, Weapon("Goo Spike", "Common", 10, 15, 50)),
        Monster("Skeleton", 45, 10, 10, 0, 3, Weapon("Bone Knife", "Uncommon", 20, 25, 100)),
        Monster("Golem", 80, 25, 30, 0, 5, Weapon("Sandstone Gauntlets", "Rare", 15, 40, 200))
    };

    theShop.fillShop(getBothLists());
}

GameData::~GameData() {
    clearBothLists();
}

int GameData::getLvlCount() {
    return this->levelCount;
}

void GameData::setLvlCount(int amount) {
    this->levelCount = amount;
}

std::vector<Item*> GameData::getBothLists() {
    bothItemLists.clear();

    for (int i = 0; i < weaponList.size(); i++) {
        bothItemLists.push_back(new Weapon(weaponList[i]));
    }
    
    for (int i = 0; i < spellList.size(); i++) {
        bothItemLists.push_back(new Spell(spellList[i]));
    }

    return bothItemLists;
}

void GameData::clearBothLists() {
    for (int i = 0; i < bothItemLists.size(); i++) {
        delete bothItemLists[i];
    }
    bothItemLists.clear();
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

Monster GameData::getMonster(const int index) {
    return this->monsterList[index];
}