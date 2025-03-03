#include "weapon_viewer.hpp"
#include <iostream>

using std::cout;
using std::endl;

void Weapon_Viewer::displayDescription(Weapon& weapon) const {
    cout << "------------------\n";
    cout << weapon.getName() << endl;
    cout << "Dmg: " << weapon.getDmg() << endl;
    cout << "Crit Chance: " << weapon.getCritChance() << "%" << endl;
    cout << "------------------\n";
}
