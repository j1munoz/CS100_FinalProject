#include "../header/enemy.hpp"

Enemy::Enemy() : Character("Enigma", 999, 999, 999, Weapon("Nothing", "N/A", 999, 999, 999)){}

float Enemy::rollDrop() {
    // Implement code here

    return 0;
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