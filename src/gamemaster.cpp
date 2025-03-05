#include "../header/gamemaster.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const GameData& GameMaster::getData() {
    return data;
}

void GameMaster::mainMenu() {
    cout << "Welcome to A Villain's Revenge!" << endl << endl;
    cout << "Please choose an option below:" << endl << endl;
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

void GameMaster::battle() {
    cout << "Battle" << endl;
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