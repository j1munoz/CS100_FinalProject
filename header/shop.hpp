#ifndef SHOP_HPP
#define SHOP_HPP

#include <vector>
#include "item.hpp"

class Shop {
        private:
                std::vector<Item> itemsForSale;

                // Private Helper Function
                void removeItem(const int&);
        public:
                Shop();
                Shop(const std::vector<Item> &);

                Item purchaseItem(const int&);               // Pass index of item to purchase
                void fillShop(const std::vector<Item> &);    // Pass array of items, choose random items to sell
                std::vector<Item> getItemsForSale() const;   // Return the items for sale
};

#endif /* SHOP_HPP */