#include <iostream>
#include <iomanip>  // For formatting
#include <random>   // For random number generator
#include <set>      // For keeping track of duplicates

#include "../header/shop.hpp"

using std::cout;
using std::endl;

void Shop::removeItem(int index) {
    itemsForSale.erase(itemsForSale.begin() + index - 1);
}

// Return bought item and call removeItem() function
// Note: The player's money will be deducted in a different function
Item Shop::purchaseItem(int index) {
    Item itemBought = itemsForSale[index-1];
    removeItem(index);

    return itemBought;
}

void Shop::displayItems() {
    // This is the length of the bar; we will use this value to
    // format the prices to be right-justified
    const int FORMATTING_LENGTH = 34;

    // Print shop items with name and price formatted
    cout << "-------------------------------------" << endl;
    for(int i = 0; i < itemsForSale.size(); ++i) {
        Item currentItem = itemsForSale[i];
        cout << (i+1) << ". " << currentItem.getName() << std::setw(FORMATTING_LENGTH - currentItem.getName().length()) 
             << "- $" << currentItem.getPrice() << endl;
    }

    cout << "\nQ. Quit" << endl;
    cout << "-------------------------------------" << endl;
}

void Shop::fillShop(std::vector<Item> &listOfItems) {
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