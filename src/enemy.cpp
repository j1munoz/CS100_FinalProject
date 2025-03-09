#include "../header/enemy.hpp"

Enemy::Enemy() : Character("Enigma", 999, 999, 999, Weapon("Nothing", "N/A", 999, 999, 999)), dropChance(999) {}

float Enemy::rollDrop() {
    return rand() % 100;
}

bool Enemy::dropItem() {
    if (rollDrop() <= dropChance) {
        return true;  // Get enemy's weapon
    } else {
        return false; // Get nothing
    }
}

float Enemy::useAttack() {
    if(currentWeapon.rollCritChance()) {
        return currentWeapon.getDmg() * 2; //Currently crits do 2x of weapons base damage
    } else {
        return currentWeapon.getDmg();
    }

    return 0;
}