#include <iostream>
#include "../header/character.hpp"
#include "../header/enemy.hpp"
#include "../header/gamedata.hpp"


#include "../header/player.hpp"
using namespace std;

void mainMenu() {
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

void battle() {
    cout << "Battle" << endl;
}

void shop() {
    cout << "View shop" << endl;
}

void viewInventory() {
    cout << "View inventory" << endl;
}

// Error check the user input
void fixBuffer() {
    cin.clear();
    cin.ignore(256, '\n');
}

int main() {
    int choice;     // Gets the user input
    Character *player = new Player;

    do {
        mainMenu();
        cin >> choice;
        fixBuffer();

        if(choice == 1) {
            battle();
        }
        else if(choice == 2) {
            shop();
        }
        else if(choice == 3) {
            viewInventory();
        }
        else if(choice != 4) {
            cout << "That is not a valid command! Try again." << endl;
        }

    } while (choice != 4 && player->isAlive());
    
    // Delete dynamically created objects/variables
    delete player;

    // Enemy list;
    // cout << list.getEnemyList()[0].getName() << endl;
    // cout << list.getEnemyList()[1].getName() << endl;
    // cout << list.getEnemyList()[2].getName() << endl;

    // Monster list2;
    // cout << list2.getMonsterList()[0].getName() << endl;
    // cout << list2.getMonsterList()[1].getName() << endl;
    // cout << list2.getMonsterList()[2].getName() << endl;

    // GameData load;

    return 0;
}