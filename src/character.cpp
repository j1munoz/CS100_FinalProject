#include "../header/character.hpp"
#include <iostream>

using std::cout;
using std::endl;

Character::Character() {}

Character::Character(const string& name, const float& totalHealth, const int& mana, const int& defense, const Weapon& currentWeapon) 
    :name(name), totalHealth(totalHealth), currentHealth(totalHealth), 
    mana(mana), maxMana(mana), defense(defense), currentWeapon(currentWeapon) {}

bool Character::isAlive() const {
    return this->currentHealth > 0;
}

string Character::getName() const {
    return name;
}

void Character::setMana(const int& amount) {
    this->mana = amount;
}

void Character::setMaxMana(const int& amount) {
    this->maxMana = amount;
}

int Character::getMana() const {
    return this->mana;
}

int Character::getMaxMana() const {
    return this->maxMana;
}

void Character::setDefense(const int& amount) {
    this->defense = amount;
}

int Character::getDefense() const {
    return this->defense;
}

void Character::setHealth(const float& amount) {
    this->currentHealth = amount;
}

float Character::getHealth() const {
    return this->currentHealth;
}

void Character::setTotalHealth(const float& amount) {
    this->totalHealth = amount;
}

float Character::getTotalHealth() const {
    return this->totalHealth;
}

void Character::displayHealth() const {
    cout << getHealth() << "/" << getTotalHealth();
}

Weapon Character::getCurrentWeapon() const {
    return currentWeapon;
}