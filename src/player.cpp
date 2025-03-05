#include "../header/player.hpp"
#include "../header/spell_viewer.hpp"
#include "../header/weapon_viewer.hpp"
#include <iostream>

using std::cout;
using std::endl;

Player::Player() {
    currency = 0;
    skillPoints = 0;
    monsterCount = 0;
    maxMonsterCount = 0;
    maxMana = 0;
    isCasting = false;
    name = "Villain";
    totalHealth = 50;
    currentHealth = 50;
    mana = 20;
    defense = 10;
}

void Player::equipItem(int index) {
    // Implement code here
}

void Player::showInventory() {
    cout << "\n--------------------------" << endl;
    
    for(int i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i].getName() << endl;
    }
    cout << "--------------------------" << endl << endl;
}

void Player::addItem(Weapon item) {
    inventory.push_back(item);
}

void Player::sellItem(int index) {
    // Implement code here
}

void Player::addSpell(Spell item) {
    spellBook.push_back(item);
}

void Player::showSpells() {
    cout << "\n--------------------------" << endl;
    for(int i = 0; i < spellBook.size(); i++) {
        cout << i + 1 << ". " << spellBook[i].getName() << endl;
    }
    cout << "--------------------------" << endl << endl;
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

int Player::getInventorySize() const {
    return inventory.size();
}

int Player::getSpellBookSize() const {
    return spellBook.size();
}

Weapon Player::getWeapon(const int& index) {
    return inventory[index];
}

Spell Player::getSpell(const int& index) {
    return spellBook[index];
}
