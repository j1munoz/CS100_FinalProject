#ifndef SPELL_VIEWER_HPP
#define SPELL_VIEWER_HPP

#include "item_viewer.hpp"
#include "spell.hpp"

class Spell_Viewer : public Item_Viewer {
    public:
    void displayDescription(Spell& spell) const; // Displays all stats of an item
};

#endif /* SPELL_VIEWER_HPP */