#ifndef ITEM_VIEWER_HPP
#define ITEM_VIEWER_HPP

#include "item.hpp"

class Item_Viewer {
    public:
    virtual void displayDescription(Item& item) const = 0; // Displays all stats of an item
};

#endif /* ITEM_VIEWER_HPP */