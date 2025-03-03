#ifndef SHOP_HPP
#define SHOP_HPP

#include <vector>
#include "item.hpp"

class Shop {
        private:
                std::vector<Item> itemsForSale;

                // Private Helper Function
                void removeItem(int);
        public:
                Shop();
                Shop(std::vector<Item> &);

                Item purchaseItem(const int);        // Pass index of item to purchase
                void fillShop(std::vector<Item> &);  // Pass array of items, choose random items to sell
};

#endif /* SHOP_HPP */