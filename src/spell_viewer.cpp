#include "spell_viewer.hpp"
#include <iostream>

using std::cout;
using std::endl;

void Spell_Viewer::displayDescription(Spell& spell) const {
    cout << "------------------\n";
    cout << spell.getName() << endl;
    cout << "Dmg: " << spell.getDmg();
    cout << "Cast Time: " << spell.getCastTime() << "Turns";
    cout << "------------------\n";
}