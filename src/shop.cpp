#include <random>   // For random number generator
#include <set>      // For keeping track of duplicates

#include "../header/shop.hpp"
#include "../header/gamedata.hpp"

// Default Constructor
Shop::Shop() {
    // Nothing to add
}

// Overloaded Constructor
Shop::Shop(std::vector<Item*> &everyItemInGame) {
    fillShop(everyItemInGame);
}

// Shop::~Shop() {
//     for (int i = 0; i < itemsForSale.size(); i++) {
//         delete itemsForSale[i];
//     }

//     itemsForSale.clear();
// }

void Shop::removeItem(int index) {
    itemsForSale.erase(itemsForSale.begin() + index - 1);
}

// Return bought item and call removeItem() function
// Note: The player's money will be deducted in a different function
Item Shop::purchaseItem(const int index) {
    Item itemBought = *itemsForSale[index-1];
    removeItem(index);

    return itemBought;
}

void Shop::fillShop(const std::vector<Item*> &listOfItems) {
    const int SHOP_CAPACITY = 5;

    itemsForSale.clear();  // Make sure vector is clear of old items

    std::set<int> duplicateItems;  // A set of integer values to keep track of chosen indices

    // Run through until shop is full of items
    for(int i = 0; i < SHOP_CAPACITY; ++i) {
        int randomIndex = rand() % listOfItems.size();

        // If the index isn't found, add item
        if(duplicateItems.find(randomIndex) == duplicateItems.end()) {
            duplicateItems.insert(randomIndex);
            itemsForSale.push_back(listOfItems[randomIndex]);
        } else {
            i--;
        }
    }
}

void Shop::initializeShop(GameData& gameData) {
    fillShop(gameData.getBothLists());  // Needed for getBothLists()
}

std::vector<Item*> Shop::getItemsForSale() const {
    return itemsForSale;
}