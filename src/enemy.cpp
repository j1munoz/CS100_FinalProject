#include "../header/enemy.hpp"

Enemy::Enemy() : Character("Enigma", 999, 999, 999, Weapon("Nothing", "N/A", 999, 999, 999)), dropChance(999) {}

float Enemy::rollDrop() const {
    return rand() % 100;
}

bool Enemy::dropItem() const {
    return rollDrop() <= dropChance;
}

float Enemy::useAttack() const {
    return (currentWeapon.rollCritChance()) ? currentWeapon.getDmg() * 2 : currentWeapon.getDmg();
}