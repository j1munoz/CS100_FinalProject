#include "../header/character.hpp"
#include <iostream>

using std::cout;
using std::endl;

Character::Character() {}

Character::Character(string name, float totalHealth, int mana, int defense, Weapon currentWeapon) 
    :name(name), totalHealth(totalHealth), currentHealth(totalHealth), 
    mana(mana), maxMana(mana), defense(defense), currentWeapon(currentWeapon) {}

bool Character::isAlive() {
    if(this->currentHealth <= 0) return false;
    return true;
}

string Character::getName() {
    return name;
}

void Character::setMana(int amount) {
    this->mana = amount;
}

int Character::getMana() {
    return this->mana;
}

int Character::getMaxMana() {
    return this->maxMana;
}

void Character::setDefense(int amount) {
    this->defense = amount;
}

int Character::getDefense() {
    return this->defense;
}

void Character::setHealth(float amount) {
    this->currentHealth = amount;
}

float Character::getHealth() {
    return this->currentHealth;
}

void Character::setTotalHealth(float amount) {
    this->totalHealth = amount;
}

float Character::getTotalHealth() {
    return this->totalHealth;
}

void Character::displayHealth() {
    cout << getHealth() << "/" << getTotalHealth();
}

Weapon Character::getCurrentWeapon() {
    return currentWeapon;
}