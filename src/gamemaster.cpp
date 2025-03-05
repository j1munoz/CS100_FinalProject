#include "../header/gamemaster.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;

const GameData& GameMaster::getData() {
    return data;
}

void GameMaster::mainMenu() {
    cout << "\nPlease choose an option below:" << endl << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Battle" << endl;
    cout << "-------------------------------------" << endl;
    cout << "2. Shop" << endl;
    cout << "-------------------------------------" << endl;
    cout << "3. View Equipment" << endl;
    cout << "-------------------------------------" << endl;
    cout << "4. Quit" << endl;
    cout << "-------------------------------------" << endl << endl;
    cout << "Select your choice: ";
}

void GameMaster::battle(Player &user) {
    const int LENGTH = 36;
    Enemy enemy;

    cout << "\nBattle" << endl << endl;
    cout << "Your Health" << setw(LENGTH * 2) << right << enemy.getName() << endl;
    cout << "======================================" << setw(LENGTH + 10) << right << "======================================\n";
    cout << setw(LENGTH / 2) << right; user.displayHealth(); 
    cout << setw(LENGTH + 7) << right; enemy.displayHealth();  
    cout << "\n======================================" << setw(LENGTH + 10) << right << "======================================\n";
}

void GameMaster::shop() {
    cout << "View shop" << endl;
}

void GameMaster::viewInventory() {
    cout << "View inventory" << endl;
}

// Error check the user input
void GameMaster::fixBuffer() {
    cin.clear();
    cin.ignore(256, '\n');
}