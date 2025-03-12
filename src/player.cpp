#include "../header/player.hpp"
#include "../header/spell_viewer.hpp"
#include "../header/weapon_viewer.hpp"
#include <iostream>

using std::cout;
using std::endl;

Player::Player() {
    currency = 300;
    skillPoints = 0;
    experience = 0;
    monsterCount = 0;
    maxMonsterCount = 3;
    maxMana = 100;
    isCasting = false;
    name = "Villain";
    totalHealth = 50;
    currentHealth = 50;
    mana = 100;
    defense = 10;
    currentWeapon = Weapon("Flimsy Sword", "Common", 10, 15, 0);

    // Starting Spells
    spellBook.push_back(Spell("Hocus Pocus", "Common", 40, 25, 2, 50));
    spellBook.push_back(Spell("Summon Slime", "Monster", 0, 40, 0, 0));
}

void Player::equipItem(const int& index) {
    currentWeapon = inventory[index];
}

void Player::showInventory() const {
    cout << "\n--------------------------" << endl;
    
    for(int i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i].getName() << endl;
    }
    cout << "--------------------------" << endl << endl;
}

void Player::addItem(const Weapon& item) {
    inventory.push_back(item);
}

void Player::removeItem(const int& index) {
    inventory.erase(inventory.begin() + index);
}

void Player::sellItem(const int& index) {
    // Implement code here
}

void Player::addSpell(const Spell& item) {
    spellBook.push_back(item);
}

void Player::showSpells() const {
    cout << "\n--------------------------" << endl;
    for(int i = 0; i < spellBook.size(); i++) {
        cout << i + 1 << ". " << spellBook[i].getName() << endl;
    }
    cout << "--------------------------" << endl << endl;
}

bool Player::getCastingStatus() const {
    return this->isCasting;
}

void Player::setCastingStatus(const bool& status) {
    this->isCasting = status;
}

int Player::getMonCount() const {
    return this->monsterCount;
}

void Player::setMonCount(const int& amount) {
    this->monsterCount = amount;
}

int Player::getMaxMonCount() const {
    return this->maxMonsterCount;
}

void Player::setMaxMonCount(const int& amount) {
    this->maxMonsterCount = amount;
}

int Player::getCurrency() const {
    return this->currency;
}

void Player::setCurrency(const int& amount) {
    this->currency = amount;
}

float Player::useAttack() const {
    return (currentWeapon.rollCritChance()) ? currentWeapon.getDmg() * 2 : currentWeapon.getDmg();
}

int Player::getInventorySize() const {
    return inventory.size();
}

int Player::getSpellBookSize() const {
    return spellBook.size();
}

void Player::displayMana() const {
    cout << mana << "/" << maxMana;
}

Weapon Player::getWeapon(const int& index) {
    return inventory[index];
}

Spell Player::getSpell(const int& index) {
    return spellBook[index];
}

std::vector<Monster>& Player::getSummonedMon() {
    return this->summonedMon;
}

void Player::setExperience(const int& exp) {
    experience = exp;
}

int Player::getExperience() const {
    return experience;
}

void Player::setSkillPoints(const int& points) {
    skillPoints = points;
}

int Player::getSkillPoints() const {
    return skillPoints;
}