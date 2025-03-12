#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using std::string;

class Item {
private:
    string name;   // Name of item
    string rarity; // Rarity of item
    float dmg;     // Amount of damage
    int price;     // Price of Item
public:
    // Implement default and overloaded constructor
    Item();
    Item(const string& name, const string& rarity, const float& dmg, const int& price);
    virtual ~Item() {}

    string getRarity() const;       // Returns rarity
    string getName() const;         // Returns name
    virtual float getDmg() const;   // Calculates damage
    void setDmg(const float&);      // Sets damage
    int getPrice() const;           // Returns price
};

#endif /* ITEM_HPP */