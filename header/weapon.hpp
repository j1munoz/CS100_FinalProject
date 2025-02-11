#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "item.hpp"

class Weapon : public Item {
        private:
                float critChance;   // Percentage of success crit

                // Private Helper Function
                bool rollCritChance();  // Returns if crit chance was successful
        public:
                // Implement default and overloaded constructor

                float getDmg() override;

                void displayDescription() override;  // Displays all stats of an item
};

#endif /* WEAPON_HPP */