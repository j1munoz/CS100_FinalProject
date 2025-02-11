#ifndef SPELL_HPP
#define SPELL_HPP

#include "item.hpp"

class Spell : public Item {
	private:
		int castTime;   // # of turns required to cast
	public:
        // Implement default and overloaded constructor

		int getCastTime();  // Returns cast time
};

#endif /* SPELL_HPP */