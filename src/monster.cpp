#include "../header/monster.hpp"

Monster::Monster() : Character("Enigma", 999, 999, 999, Weapon("Nothing", "N/A", 999, 999, 999)), lifetime(999){}

int Monster::getLifetime() {
    return this->lifetime;
}

void Monster::setLifetime(int amount) {
    this->lifetime = amount;
}

float Monster::useAttack() {
    // Implement code here

    return 0;
}