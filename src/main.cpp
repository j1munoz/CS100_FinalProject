#include <iostream>

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

    return 0;
}