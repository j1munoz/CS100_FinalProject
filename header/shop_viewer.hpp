#ifndef SHOP_VIEWER_HPP
#define SHOP_VIEWER_HPP

#include <vector>
#include "item.hpp"

class Shop_Viewer {
        public:
        void displayItems(const std::vector<Item> &) const;  // Display items in the shop with prices
};

#endif /* SHOP_VIEWER_HPP */