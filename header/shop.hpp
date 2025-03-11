#ifndef SHOP_HPP
#define SHOP_HPP

#include <vector>
#include "item.hpp"
class GameData;

class Shop {
        private:
                std::vector<Item*> itemsForSale;

                // Private Helper Function
                void removeItem(int);
        public:
                Shop();
                Shop(std::vector<Item*> &);
                ~Shop();

                Item purchaseItem(const int);               // Pass index of item to purchase
                void fillShop(const std::vector<Item*> &);         // Pass array of items, choose random items to sell
                void initializeShop(GameData& gameData);
                std::vector<Item*> getItemsForSale() const;  // Return the items for sale

};

#endif /* SHOP_HPP */