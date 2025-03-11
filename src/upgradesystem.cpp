#include "../header/upgradesystem.hpp"

void UpgradeSystem::increaseHealth(Player& user, const int& amount) const {
    user.setTotalHealth(amount);
}

void UpgradeSystem::increaseDef(Player& user, const int& amount) const {
    user.setDefense(amount);
}

void UpgradeSystem::increaseMana(Player& user, const int& amount) const {
    user.setMaxMana(amount);
}

void UpgradeSystem::increaseMonsterCount(Player& user, const int& amount) const {
    user.setMaxMonCount(amount);
}