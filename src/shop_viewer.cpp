#include <iostream>
#include <iomanip>  // For formatting

#include "../header/shop_viewer.hpp"

using std::cout;
using std::endl;

void Shop_Viewer::displayItems(const std::vector<Item*> &itemsForSale) const {
    // This is the length of the bar; we will use this value to
    // format the prices to be right-justified
    const int FORMATTING_LENGTH = 30;

    // Print shop items with name and price formatted
    cout << "-------------------------------------" << endl;
    if(itemsForSale.size() > 0) {
        for(int i = 0; i < itemsForSale.size(); ++i) {
            Item* currentItem = itemsForSale[i];
            cout << (i+1) << ". " << currentItem->getName() << std::setw(FORMATTING_LENGTH - currentItem->getName().length()) 
                 << "- $" << currentItem->getPrice() << endl;
        }
    
        cout << "\nQ. Quit" << endl;
    } else {
        cout << "There are no items to display at this moment." << endl;
    }
    cout << "-------------------------------------" << endl;
}
