#include "../header/item.hpp"

Item::Item() : name(""), rarity("Common"), dmg(0), price(0) {}

Item::Item(string name, string rarity, float dmg, int price) : name(name), rarity(rarity), dmg(dmg), price(price) {}

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