#include "../header/upgradesystem.hpp"

void UpgradeSystem::increaseHealth(Character& user, int amount) {
    user.setTotalHealth(amount);
}
void UpgradeSystem::increasePhysAtk(Character& user, int amount) {

}

void UpgradeSystem::inncreaseMgAtk(Character& user, int amount) {

}

void UpgradeSystem::increaseDef(Character& user, int amount) {
    user.setDefense(amount);
}

void UpgradeSystem::increaseMana(Character& user, int amount) {
    user.setMana(amount);
} 