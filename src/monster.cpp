#include "../header/monster.hpp"

Monster::Monster() : Character("Enigma", 999, 999, 999, Weapon("Nothing", "N/A", 999, 999, 999)), lifetime(999){}

int Monster::getLifetime() const {
    return this->lifetime;
}

void Monster::setLifetime(const int& amount) {
    this->lifetime = amount;
}

int Monster::getMaxLifetime() const {
    return this->maxLifetime;
}

void Monster::setMaxLifetime(const int& amount) {
    this->lifetime = amount;
}

float Monster::useAttack() const {
    return (currentWeapon.rollCritChance()) ? currentWeapon.getDmg() * 2 : currentWeapon.getDmg();
}