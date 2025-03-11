#include "../header/upgradesystem.hpp"

void UpgradeSystem::increaseHealth(Player& user, const int& amount) {
    user.setTotalHealth(amount);
}

void UpgradeSystem::increaseDef(Player& user, const int& amount) {
    user.setDefense(amount);
}

void UpgradeSystem::increaseMana(Player& user, const int& amount) {
    user.setMaxMana(amount);
}

void UpgradeSystem::increaseMonsterCount(Player& user, const int& amount) {
    user.setMaxMonCount(amount);
}