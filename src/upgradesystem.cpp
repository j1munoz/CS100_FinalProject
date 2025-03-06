#include "../header/upgradesystem.hpp"

void UpgradeSystem::increaseHealth(Player& user, int amount) {
    this->setTotalHealth(amount);
}
void UpgradeSystem::increasePhysAtk(Player& user, int amount) {

}

void UpgradeSystem::inncreaseMgAtk(Player& user, int amount) {

}

void UpgradeSystem::increaseDef(Player& user, int amount) {
    this->setDefense(amount);
}

void UpgradeSystem::increaseMana(Player& user, int amount) {
    this->setMana(amount);
} 