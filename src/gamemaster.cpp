#include "../header/gamemaster.hpp"
#include "../header/spell_viewer.hpp"
#include "../header/weapon_viewer.hpp"
#include "../header/player.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;

// Generic helper function to display player choices
void displayChoiceMenu() {
    cout << "\n--------------------------------------\n";
    cout << "1. Fight" << endl;
    cout << "2. View Inventory" << endl;
    cout << "3. Run";
    cout << "\n--------------------------------------\n\n";
}

// Generic helper function to display attack menu
void displayAttackMenu() {
    cout << "How will you fight?" << endl;
    cout << "\n--------------------------------------\n";
    cout << "1. Physical Attack" << endl;
    cout << "2. Spell" << endl;
    cout << "3. Go Back";
    cout << "\n--------------------------------------\n\n";
}

GameData& GameMaster::getData() {
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

void GameMaster::battle() {
    const int LENGTH = 36;

    Enemy enemy;

    // We pass by reference so we can edit the actual values of Player
    Player &player = data.getPlayer();

    cout << "\nBattle" << endl << endl;

    // do while loop here...
    cout << "Your Health" << setw(LENGTH * 2) << right << enemy.getName() << endl;
    cout << "======================================" << setw(LENGTH + 10) << right << "======================================\n";
    cout << setw(LENGTH / 2) << right; player.displayHealth(); 
    cout << setw(LENGTH + 7) << right; enemy.displayHealth();  
    cout << "\n======================================" << setw(LENGTH + 10) << right << "======================================\n";

    do {
        int userMenuChoice;
        displayChoiceMenu();
    
        cout << "Select your choice: ";
        cin >> userMenuChoice;
        fixBuffer();  // Filter out junk input

        if(userMenuChoice == 1) {
            // Attack here
            do {
                int userAttackChoice;
                displayAttackMenu();
    
                cout << "Select your attack: ";
                cin >> userAttackChoice;
                fixBuffer();
    
                if(userAttackChoice == 1) {
                    // Implement physical attack here
                    break;
                } else if(userAttackChoice == 2) {
                    // Implement spell here
                    break;
                } else if(userAttackChoice == 3) {
                    // Go back to menu choices
                    break;
                } else {
                    // Invalid input
                    cout << "\nThat is not a valid command! Try again." << endl;
                }
            } while(true);
        } else if(userMenuChoice == 2) {
            // View inventory here
            viewInventory();
        } else if(userMenuChoice == 3) {
            // Running away
            cout << "You have run away from the battle. Returning back to Main Menu..." << endl;
            break;
        } else {
            // Invalid input
            cout << "\nThat is not a valid command! Try again." << endl << endl;
        }
    } while(true);
}

void GameMaster::shop() {
    cout << "View shop" << endl;
}

void GameMaster::viewInventory() {
    int inventoryChoice;
    Player player;
    player = data.getPlayer();

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
                    if(player.getSpellBookSize() == 0) {
                        cout << "\nYour spell book is currently empty.\n" << endl;
                    } else {
                        player.showSpells();
                            
                        int viewSpell;
                        do {
                            cout << "Select the item you would like to inspect: ";
                            cin >> viewSpell;
                            fixBuffer();

                            if(viewSpell >= 1 && viewSpell <= player.getInventorySize()) {
                                Spell_Viewer viewSpellStats;
                                Spell showSpell = player.getSpell(viewSpell - 1);

                                viewSpellStats.displayDescription(showSpell);
                            } else {
                                outputError();
                            }

                        } while(viewSpell < 1 || viewSpell > player.getInventorySize());
                    }

                } else if(toupper(viewItemChoice) == 'W') {
                    if(player.getInventorySize() == 0) {
                        cout << "\nYour inventory is currently empty.\n" << endl;
                    } else {
                        player.showInventory();

                        int viewWeapon;
                        do {
                            cout << "Select the item you would like to inspect: ";
                            cin >> viewWeapon;
                            fixBuffer();

                            if(viewWeapon >= 1 && viewWeapon <= player.getInventorySize()) {
                                Weapon_Viewer viewWeaponStats;
                                Weapon showWeapon = player.getWeapon(viewWeapon - 1);

                                viewWeaponStats.displayDescription(showWeapon);
                            } else {
                                outputError();
                            }

                        } while(viewWeapon < 1 || viewWeapon > player.getInventorySize());
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

void GameMaster::viewInventoryMenu() {
    cout << "You are now in your inventory." << endl << endl;
    cout << "--------------------------" << endl;
    cout << "1. Equip Item" << endl;
    cout << "2. View Weapons/Spells" << endl;
    cout << "3. Quit" << endl;
    cout << "--------------------------" << endl << endl;
    cout << "Select your choice: ";
}

void GameMaster::equipItem() {
    cout << "Equip item" << endl;
}

// Error check the user input
void GameMaster::fixBuffer() {
    cin.clear();
    cin.ignore(256, '\n');
}

void GameMaster::outputError() {
    cout << "\nThat is not a valid command! Try again." << endl << endl;
}