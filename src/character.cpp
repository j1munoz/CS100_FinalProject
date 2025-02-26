#include "../header/character.hpp"

Character::Character() {}

bool Character::isAlive() {
    if(this->currentHealth <= 0) return false;
    return true;
}

int Character::getMana() {
    return this->mana;
}

void Character::setMana(int amount) {
    this->mana = amount;
}

int Character::getMaxMana() {
    return this->maxMana;
}

void Character::displayHealth() {
    // Implement code here
}

float Character::getHealth() {
    return this->currentHealth;
}

void Character::setHealth(float amount) {
    this->currentHealth = amount;
}

float Character::getTotalHealth() {
    return this->totalHealth;
}

void Character::setTotalHealth(float amount) {
    this->totalHealth = amount;
}

int Character::getDefense() {
    return this->defense;
}

void Character::setDefense(int amount) {
    this->defense = amount;
}