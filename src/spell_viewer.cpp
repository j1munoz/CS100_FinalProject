#include "../header/spell_viewer.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

void Spell_Viewer::displayDescription(Item& item) const {
    Spell& spell = static_cast<Spell&>(item);
    const int NAME_LENGTH = spell.getName().length();
    const int CENTER = (38 - NAME_LENGTH) / 2; // 38 is the Number of Dashes

    cout << "--------------------------------------\n";
    cout << setw(CENTER + NAME_LENGTH) << right << spell.getName() << endl;
    cout << setw(15) << left << "Dmg:" << spell.getDmg() << endl;
    cout << setw(15) << left << "Cast Time:" << spell.getCastTime() << " Turns" << endl;
    cout << "--------------------------------------\n";
}