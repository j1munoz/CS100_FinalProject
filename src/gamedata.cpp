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
        Weapon("Hammer of Giants", "Legendary", 30, 65, 500)
        
    };
    spellList = {
        // | Name | Rarity | Damage | Mana Cost | Cast Time | Sell Price | Monster Index
        Spell("Summon Slime", "Monster", 0, 40, 0, 50, 0),
        Spell("Summon Skeleton", "Monster", 0, 65, 0, 200, 1),
        Spell("Summon Golem", "Monster", 0, 80, 0, 500, 2),
        Spell("Summon Nymph", "Monster", 0, 45, 0, 400, 3),
        Spell("Summon Ifrit", "Monster", 0, 100, 0, 1000, 4),
        Spell("Fireball", "Common", 30, 10, 1, 50, -1),
        Spell("Ice Trap", "Uncommon", 45, 15, 1, 100, -1),
        Spell("Lighting Wave", "Rare", 60, 20, 2, 150, -1),
        Spell("Meteor Shower", "Legendary", 100, 50, 3, 600, -1)
    };

    enemyList = {
        //Format is as follows for hardcoding enemies:
        //| Name | Health | Mana | Defense | Weapon | Drop Chance
        Enemy("Peasent", 15, 0, 2, Weapon("Pitchfork", "Common", 10, 15, 50), 50),
        Enemy("Adventurer", 30, 10, 5, Weapon("Scimitar", "Uncommon", 20, 20, 100), 25),
        Enemy("Rogue", 25, 20, 10, Weapon("Knife", "Common", 10, 45, 60), 35),
        Enemy("Archer", 10, 40, 0, Weapon("Bow", "Uncommon", 35, 10, 300), 65),
        Enemy("Knight", 150, 25, 15, Weapon("Crusader Hammer", "Rare", 15, 30, 200), 15),
        Enemy("Prince", 250, 50, 10, Weapon("Royal Blade", "Legendary", 20, 80, 100), 5)
    };
  
    monsterList = {
        //Format is as follows for hardcoding monsters:
        //| Name | Health | Mana | Defense | Lifetime | Max Lifetime | Weapon |
        Monster("Slime", 15, 0, 2, 0, 2, Weapon("Goo Spike", "Common", 10, 15, 50)),
        Monster("Skeleton", 45, 10, 10, 0, 3, Weapon("Bone Knife", "Uncommon", 20, 25, 100)),
        Monster("Golem", 80, 25, 25, 0, 5, Weapon("Sandstone Gauntlets", "Rare", 15, 40, 200)),
        Monster("Nymph", 10, 60, 5, 0, 4, Weapon("Pixie Dust", "Rare", 15, 90, 450)),
        Monster("Ifrit", 120, 75, 30, 0, 3, Weapon("Hand Canon", "Legendary", 45, 40, 800))
    };

    levelCount = 1;

    theShop.fillShop(getBothLists());
}

GameData::~GameData() {
    clearBothLists();
}

int GameData::getLvlCount() const {
    return this->levelCount;
}

void GameData::setLvlCount(const int& level) {
    this->levelCount = level;
}

std::vector<Item*> GameData::getBothLists() {
    clearBothLists();

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

void GameData::setPlayer(const Player& user) {
    this->user = user;
}

Monster GameData::getMonster(const int& index) const{
    return this->monsterList[index];
}

std::vector<Enemy>& GameData::getEnemyList() {
    return this->enemyList;
}