#ifndef WEAPON_VIEWER_HPP
#define WEAPON_VIEWER_HPP

#include "item_viewer.hpp"

class Weapon_Viewer : public Item_Viewer{
    public:
    void displayDescription() override; // Displays all stats of an item
};

#endif /* WEAPON_VIEWER_HPP */