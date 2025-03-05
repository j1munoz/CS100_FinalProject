#ifndef WEAPON_VIEWER_HPP
#define WEAPON_VIEWER_HPP

#include "item_viewer.hpp"
#include "weapon.hpp"

class Weapon_Viewer : public Item_Viewer {
    public:
    void displayDescription(Item& item) const override; // Displays all stats of an item
};

#endif /* WEAPON_VIEWER_HPP */