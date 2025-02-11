#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using std::string;

class Item {
	private:
		string rarity;      // Rarity of item
        string name;        // Name of item
        float dmg;          // Amount of damage
        int price;          // Price of Item
	public:
        // Implement default and overloaded constructor

		string getRarity();         // Returns rarity
        string getName();           // Returns name
        virtual float getDmg();     // Calculates damage
        void setDmg(float);         // Sets damage
        int getPrice();             // Returns price
        
        virtual void displayDescription();  // Displays all stats of an item
};

#endif /* ITEM_HPP */