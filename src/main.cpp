#include <iostream>
#include "../header/gamedata.hpp"
#include "../header/player.hpp"
#include "../header/character.hpp"
#include "../header/enemy.hpp"
#include "../header/item.hpp"
#include "../header/weapon_viewer.hpp"
#include "../header/spell_viewer.hpp"

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

void viewInventoryMenu() {
    cout << "You are now in your inventory." << endl << endl;
    cout << "--------------------------" << endl;
    cout << "1. Equip Item" << endl;
    cout << "2. View Weapons/Spells" << endl;
    cout << "3. Quit" << endl;
    cout << "--------------------------" << endl << endl;
    cout << "Select your choice: ";
}

void equipItem() {
    cout << "Equip an item" << endl;
}

// Error check the user input
void fixBuffer() {
    cin.clear();
    cin.ignore(256, '\n');
}

void outputError() {
    cout << "\nThat is not a valid command! Try again." << endl << endl;
}

int main() {
    int choice;     // Gets the user input
    Player *player = new Player;

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
            int inventoryChoice;
            do {
                viewInventoryMenu();
                cin >> inventoryChoice;
                fixBuffer();

                if(inventoryChoice == 1) {
                    equipItem();
                } else if(inventoryChoice == 2) {
                    char viewItemChoice;

                    do {
                        cout << "Would you like to view Spells <S>, Weapons <W>, or Quit <Q>?" << endl;
                        cout << "Select your choice: ";
                        cin >> viewItemChoice;
                        fixBuffer();

                        if(toupper(viewItemChoice) == 'S') {
                            if(player->getSpellBookSize() == 0) {
                                cout << "Your spell book is currently empty." << endl;
                            } else {
                                player->showSpells();
                            
                                int viewSpell;
                                do {
                                    cout << "Select the item you would like to inspect: ";
                                    cin >> viewSpell;
                                    fixBuffer();

                                    if(viewSpell >= 1 && viewSpell <= player->getInventorySize()) {
                                        Spell_Viewer viewSpellStats;
                                        Spell showSpell = player->getSpell(viewSpell - 1);

                                        viewSpellStats.displayDescription(showSpell);
                                    } else {
                                        outputError();
                                    }

                                } while(viewSpell < 1 || viewSpell > player->getInventorySize());
                            }

                        } else if(toupper(viewItemChoice) == 'W') {
                            if(player->getInventorySize() == 0) {
                                cout << "Your inventory is currently empty." << endl;
                            } else {
                                player->showInventory();

                                int viewWeapon;
                                do {
                                    cout << "Select the item you would like to inspect: ";
                                    cin >> viewWeapon;
                                    fixBuffer();

                                    if(viewWeapon >= 1 && viewWeapon <= player->getInventorySize()) {
                                        Weapon_Viewer viewWeaponStats;
                                        Weapon showWeapon = player->getWeapon(viewWeapon - 1);

                                        viewWeaponStats.displayDescription(showWeapon);
                                    } else {
                                        outputError();
                                    }

                                } while(viewWeapon < 1 || viewWeapon > player->getInventorySize());
                            }

                        } else if(toupper(viewItemChoice) != 'Q') {
                            outputError();
                        }
                    } while(toupper(viewItemChoice) != 'Q');

                } else if(inventoryChoice != 3) {
                    outputError();
                }
            } while(inventoryChoice != 3);
        }
        else if(choice != 4) {
            outputError();
        }

    } while (choice != 4 && player->isAlive());
    
    // Delete dynamically created objects/variables
    delete player;

    return 0;
}
