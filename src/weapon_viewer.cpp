#include "../header/weapon_viewer.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

void Weapon_Viewer::displayDescription(Item& item) const {
    Weapon& weapon = static_cast<Weapon&>(item);
    const int NAME_LENGTH = weapon.getName().length();
    const int CENTER = (38 - NAME_LENGTH) / 2; // 38 is the Number of Dashes

    cout << "--------------------------------------\n";
    cout << setw(CENTER + NAME_LENGTH) << right << weapon.getName() << endl;
    cout << setw(15) << left << "Dmg:" << weapon.getDmg() << endl;
    cout << setw(15) << left << "Crit Chance:" << weapon.getCritChance() << "%" << endl;
    cout << "--------------------------------------\n";
}
