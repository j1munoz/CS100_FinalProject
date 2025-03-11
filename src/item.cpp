#include "../header/item.hpp"

Item::Item() : name(""), rarity("Common"), dmg(0), price(0) {}

Item::Item(const string& name, const string& rarity, const float& dmg, const int& price) : name(name), rarity(rarity), dmg(dmg), price(price) {}

string Item::getRarity() const {
    return this->rarity;
}

string Item::getName() const {
    return this->name;
}

float Item::getDmg() const {
    return this->dmg;
}

void Item::setDmg(const float& amount) {
    this->dmg = amount;
}

int Item::getPrice() const {
    return this->price;
}