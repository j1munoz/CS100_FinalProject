#include "../header/player.hpp"

void Player::equipItem(int index) {
    // Implement code here
}

void Player::showInventory() {
    // Implement code here
}

void Player::addItem(Weapon item) {
    // Implement code here
}

void Player::sellItem(int index) {
    // Implement code here
}

void Player::addSpell(Spell item) {
    // Implement code here
}

void Player::showSpells() {
    // Implement code here
}

bool Player::getCastingStatus() {
    return this->isCasting;
}

void Player::setCastingStatus(bool status) {
    this->isCasting = status;
}

int Player::getMonCount() {
    return this->monsterCount;
}

void Player::setMonCount(int amount) {
    this->monsterCount = amount;
}

int Player::getMaxMonCount() {
    return this->maxMonsterCount;
}

void Player::setMaxMonCount(int amount) {
    this->maxMonsterCount = amount;
}

void Player::increaseHealth(float amount) {
    this->setTotalHealth(amount);
}

void Player::increaseDef(int amount) {
    this->setDefense(amount);
}

int Player::getCurrency() {
    return this->currency;
}

void Player::setCurrenct(int amount) {
    this->currency = amount;
}

float Player::useAttack() {
    // Implement code here

    return 0;
}

float Player::useSpell() {
    // Implement code here

    return 0;
}