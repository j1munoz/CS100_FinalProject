#include "../header/monster.hpp"

Monster::Monster() : Character("Enigma", 999, 999, 999, Weapon("Nothing", "N/A", 999, 999, 999)), lifetime(999){}

int Monster::getLifetime() {
    return this->lifetime;
}

void Monster::setLifetime(int amount) {
    this->lifetime = amount;
}

int Monster::getMaxLifetime() {
    return this->maxLifetime;
}

void Monster::setMaxLifetime(int amount) {
    this->lifetime = amount;
}

float Monster::useAttack() {
    if(currentWeapon.rollCritChance()) {
        return currentWeapon.getDmg() * 2; //Currently crits do 2x of weapons base damage
    }
    else {
        return currentWeapon.getDmg();
    }

    return 0;

    return 0;
}