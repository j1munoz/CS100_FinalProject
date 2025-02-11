#include "../header/item.hpp"

string Item::getRarity() {
    return this->rarity;
}

string Item::getName() {
    return this->name;
}

float Item::getDmg() {
    return this->dmg;
}

void Item::setDmg(float amount) {
    this->dmg = amount;
}

int Item::getPrice() {
    return this->price;
}

void Item::displayDescription() {
    // Implement code here
}