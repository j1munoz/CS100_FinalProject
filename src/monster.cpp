#include "../header/monster.hpp"

Monster::Monster() : Character("Enigma", 999, 999, 999), lifetime(999){}

        //Format is as follows for hardcoding monsters:
        //| Name | Health | Mana | Defense | Lifetime |

std::vector<Monster> Monster::monsterList ={
        Monster("Slime", 10, 0, 2, 5),
        Monster("Skeleton", 30, 10, 10, 5),
        Monster("Golem", 80, 25, 30, 5)
};

vector<Monster>& Monster::getMonsterList() {
    return monsterList;
}

string Monster::getName() const {
    return name;
}

int Monster::getLifetime() {
    return this->lifetime;
}

void Monster::setLifetime(int amount) {
    this->lifetime = amount;
}

float Monster::useAttack() {
    // Implement code here

    return 0;
}

float Monster::useSpell() {
    // Implement code here

    return 0;
}