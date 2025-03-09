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

    // Temporary enemy place holder
    // Implement enemy generation here ------------------------------------------------------------------
    Enemy enemy("Training Dummy", 50, 0, 5, Weapon("Stick Arm", "Common", 1, 5, 0), 75);

    // We pass by reference so we can edit the actual values of Player
    Player &player = data.getPlayer();

    cout << "\nBattle" << endl << endl;
    int turnCount = 0;

    do {
        turnCount++;
        cout << "Turn " << turnCount << endl << endl;

        cout << "Your Health" << setw(LENGTH * 2) << right << enemy.getName() << endl;
        cout << "======================================" << setw(LENGTH + 10) << right << "======================================\n";
        cout << setw(LENGTH / 2) << right; player.displayHealth(); 
        cout << setw(LENGTH + 7) << right; enemy.displayHealth();  
        cout << "\n======================================" << setw(LENGTH + 10) << right << "======================================\n";

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
                    // Calculate damage done
                    float dmgValue = player.useAttack() - enemy.getDefense();
                    float dmgDone = (dmgValue > 0) ? dmgValue : 0;

                    float healthValue = enemy.getHealth() - dmgDone;
                    float remainingHealth = (healthValue > 0) ? healthValue : 0;

                    enemy.setHealth(remainingHealth);

                    // Display damage done (critical hit or not)
                    if(dmgValue + enemy.getDefense() == player.getCurrentWeapon().getDmg()*2) {
                        cout << "You have attacked the " << enemy.getName() << " for " << dmgDone << "* DMG! (Critical HIT)" << endl;
                    } else {
                        cout << "You have attacked the " << enemy.getName() << " for " << dmgDone << " DMG!" << endl;
                    }

                    // Insert enemy attack here ------------------------------------------------------------------

                    break;
                } else if(userAttackChoice == 2) {
                    // Implement spell here ------------------------------------------------------------------
                    break;
                } else if(userAttackChoice == 3) {
                    // Go back to menu choices
                    break;
                } else {
                    // Invalid input
                    outputError();
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
            outputError();
        }
    } while(player.isAlive() && enemy.isAlive());

    if(!enemy.isAlive()) {
        cout << "Congratulations! You have successfully won the battle against " << enemy.getName() << "!" << endl;

        // Drop enemy loot
        if(enemy.dropItem()) {
            cout << "You have received the following item: " << enemy.getCurrentWeapon().getName() << endl;
            player.addItem(enemy.getCurrentWeapon());
        }

        // Get cash reward
        int cashPrize = rand() % 500;
        player.setCurrency(cashPrize + player.getCurrency());
        cout << "You have recieved $" << cashPrize << " for your efforts!" << endl;

        cout << "Returning to Main Menu..." << endl;
    }

    // Reset player values
    player.setHealth(player.getTotalHealth());
    player.setMana(player.getMaxMana());
    player.setCastingStatus(false);
    player.setMonCount(0);
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