#include "../header/enemy.hpp"

Enemy::Enemy() : Character("Enigma", 999, 999, 999){}

        //Format is as follows for hardcoding enemies:
        //| Name | Health | Mana | Defense |

std::vector<Enemy> Enemy::enemyList ={
        Enemy("Peasent", 10, 0, 2),
        Enemy("Adventurer", 30, 10, 10),
        Enemy("Knight", 80, 25, 30)
};

float Enemy::rollDrop() {
    // Implement code here

    return 0;
}

vector<Enemy>& Enemy::getEnemyList() { 
    return enemyList; 
}

string Enemy::getName() const {

    return name;
}

Item Enemy::dropItem() {
    // Implement code here
    // You will call rollDrop here to see if an Item will drop

    Item temp;
    return temp;
}

float Enemy::useAttack() {
    // Implement code here

    return 0;
}

float Enemy::useSpell() {
    // Implement code here

    return 0;
}