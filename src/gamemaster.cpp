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

struct SpellInfo {
    SpellInfo(int time, Spell spell) : timeElapsed(time), spell(spell) {}

    int timeElapsed;
    Spell spell;
};

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
    const int HEALTH_BAR_LENGTH = 36;
    const int MANA_BAR_LENGTH = 20;
    const int MANA_REGEN = 10;

    SpellInfo *spellInfo = nullptr;

    // Temporary enemy place holder
    // Implement enemy generation here ------------------------------------------------------------------
    Enemy enemy("Training Dummy", 200, 0, 5, Weapon("Stick Arm", "Common", 1, 11, 0), 75);

    // We pass by reference so we can edit the actual values of Player
    Player &player = data.getPlayer();

    cout << "\nBattle" << endl << endl;
    int turnCount = 1;

    do {
        cout << "Turn " << turnCount << endl << endl;

        cout << "Your Mana" << endl;
        cout << "====================" << endl;
        cout << setw(MANA_BAR_LENGTH / 2) << right; player.displayMana();
        cout << "\n====================" << endl;

        cout << "Your Health" << setw(HEALTH_BAR_LENGTH * 2) << right << enemy.getName() << endl;
        cout << "======================================" << setw(HEALTH_BAR_LENGTH + 10) << right << "======================================\n";
        cout << setw(HEALTH_BAR_LENGTH / 2) << right; player.displayHealth(); 
        cout << setw(HEALTH_BAR_LENGTH + 7) << right; enemy.displayHealth();  
        cout << "\n======================================" << setw(HEALTH_BAR_LENGTH + 10) << right << "======================================\n";

        for(int i = player.getSummonedMon().size() - 1; i >= 0; --i) {
            if(player.getSummonedMon()[i].getLifetime() > player.getSummonedMon()[i].getMaxLifetime()) {
                player.getSummonedMon().erase(player.getSummonedMon().begin() + i);
                player.setMonCount(player.getSummonedMon().size());
            } else {
                cout << "\n" << player.getSummonedMon()[i].getName() << " Health (Lifetime: " 
                << player.getSummonedMon()[i].getLifetime() << "/" << player.getSummonedMon()[i].getMaxLifetime() << ")" << endl;
                cout << "======================================" << endl;
                cout << setw(HEALTH_BAR_LENGTH / 2) << right; player.getSummonedMon()[i].displayHealth(); 
                cout << "\n======================================" << endl;
            }
        }

        int userMenuChoice;
        displayChoiceMenu();
    
        cout << "Select your choice: ";
        cin >> userMenuChoice;
        fixBuffer();  // Filter out junk input

        bool playerTurnActive = true; // Whether player has gone or not
        
        if(userMenuChoice == 1) {
            // Attack here
            if(player.getCastingStatus()) {
                if(spellInfo->timeElapsed == spellInfo->spell.getCastTime()) {
                    player.setCastingStatus(false);
    
                    // Calculate damage done
                    float dmgValue = spellInfo->spell.getDmg() - enemy.getDefense();
                    float dmgDone = (dmgValue > 0) ? dmgValue : 0;
    
                    float healthValue = enemy.getHealth() - dmgDone;
                    float remainingHealth = (healthValue > 0) ? healthValue : 0;
    
                    enemy.setHealth(remainingHealth);
    
                    cout << endl;
                    cout << "You casted " << spellInfo->spell.getName() << " on " << enemy.getName() << " for " << dmgDone << " DMG!" << endl;
                } else {
                    cout << "You are casting " << spellInfo->spell.getName() 
                    << " (" << spellInfo->timeElapsed << "/" << spellInfo->spell.getCastTime() << ")" << endl;
                }
                playerTurnActive = false;
            } else {
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
                        cout << endl;
                        if(dmgValue + enemy.getDefense() == player.getCurrentWeapon().getDmg()*2) {
                            cout << "You have attacked the " << enemy.getName() << " for " << dmgDone << "* DMG! (Critical HIT)" << endl;
                        } else {
                            cout << "You have attacked the " << enemy.getName() << " for " << dmgDone << " DMG!" << endl;
                        }
    
                        playerTurnActive = false;
                        break;
                    } else if(userAttackChoice == 2) {
                        // Cast a Spell
                        do {
                            cout << "What Spell would you like to cast?" << endl;
                            player.showSpells();
                            
                            int spellChoice;
                            cout << "Select your choice: ";
                            cin >> spellChoice;
                            fixBuffer();
    
                            // If valid choice
                            if(spellChoice > 0 && spellChoice <= player.getSpellBookSize()) {
                                // If the player has enough mana
                                if(player.getMana() >= player.getSpell(spellChoice-1).getManaCost()) {
                                    int manaValue = player.getMana() - player.getSpell(spellChoice-1).getManaCost();
                                    int remainingMana = (manaValue > 0) ? manaValue : 0;
    
                                    player.setMana(remainingMana);
    
                                    // If a summoning spell, instantly summon (for next turn)
                                    if(player.getSpell(spellChoice-1).getRarity() == "Monster") {
                                        if(player.getMonCount() == player.getMaxMonCount()) {
                                            player.setMana(player.getSpell(spellChoice-1).getManaCost());
                                            cout << "You are at the limit for summoning monsters!!!" << endl;
                                        } else {
                                            // We are using the selling price as a index for now
                                            Monster minion = data.getMonster(player.getSpell(spellChoice-1).getPrice());
    
                                            player.setMonCount(player.getMonCount() + 1);
                                            player.getSummonedMon().push_back(minion);
    
                                            cout << "You have summoned a " << minion.getName() << " for " << minion.getMaxLifetime() << " turns!" << endl;
                                            playerTurnActive = false;
                                        }
                                    } else {
                                        player.setCastingStatus(true);
                                        playerTurnActive = false;
    
                                        delete spellInfo;
                                        spellInfo = new SpellInfo(0, player.getSpell(spellChoice - 1));
                                    }
                                } else {
                                    cout << "\nYou don't have enough mana to use this spell!" << endl;
                                }
                                break;
                            } else {
                                outputError();
                            }
                        } while(true);
                        break;
                    } else if(userAttackChoice == 3) {
                        // Go back to menu choices
                        break;
                    } else {
                        // Invalid input
                        outputError();
                    }
                } while(true);
            }
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

        // Minions move
        if(playerTurnActive == false && player.getMonCount() != 0) {
            for(int i = 0; i < player.getMonCount(); ++i) {
                player.getSummonedMon()[i].setLifetime(player.getSummonedMon()[i].getLifetime() + 1);

                // Minion attack
                float minionDmgValue = player.getSummonedMon()[i].useAttack() - enemy.getDefense();
                float minionDmgDone = (minionDmgValue > 0) ? minionDmgValue : 0;

                float healthValue = enemy.getHealth() - minionDmgDone;
                float remainingHealth = (healthValue > 0) ? healthValue : 0;

                enemy.setHealth(remainingHealth);

                // Display damage done (critical hit or not)
                if(minionDmgValue + enemy.getDefense() == player.getSummonedMon()[i].getCurrentWeapon().getDmg()*2) {
                    cout << player.getSummonedMon()[i].getName() << " attacks " << enemy.getName() << " for " << minionDmgDone << "* DMG! (Critical HIT)" << endl;
                } else {
                    cout << player.getSummonedMon()[i].getName() << " attacks " << enemy.getName() << " for " << minionDmgDone << " DMG!" << endl;
                }
            }
        }

        // Enemy attacks back
        if(enemy.isAlive() && playerTurnActive == false) {
            int enemyTarget = player.getMonCount() != 0 ? (rand() % player.getMonCount()) + 1 : 1;

            // Enemy attacks player; else minion
            if(enemyTarget == 1) {
                float dmgValue = enemy.useAttack() - player.getDefense();
                float dmgDone = (dmgValue > 0) ? dmgValue : 0;

                float healthValue = player.getHealth() - dmgDone;
                float remainingHealth = (healthValue > 0) ? healthValue : 0;

                player.setHealth(remainingHealth);

                // Display damage done (critical hit or not)
                if(dmgValue + player.getDefense() == enemy.getCurrentWeapon().getDmg()*2) {
                    cout << enemy.getName() << " attacks YOU for " << dmgDone << "* DMG! (Critical HIT)" << endl << endl;
                } else {
                    cout << enemy.getName() << " attacks YOU for " << dmgDone << " DMG!" << endl << endl;
                }
            } else {
                float dmgValue = enemy.useAttack() - player.getSummonedMon()[enemyTarget-1].getDefense();
                float dmgDone = (dmgValue > 0) ? dmgValue : 0;

                float healthValue = player.getSummonedMon()[enemyTarget-1].getHealth() - dmgDone;
                float remainingHealth = (healthValue > 0) ? healthValue : 0;

                player.getSummonedMon()[enemyTarget-1].setHealth(remainingHealth);

                // Display damage done (critical hit or not)
                if(dmgValue + player.getSummonedMon()[enemyTarget-1].getDefense() == enemy.getCurrentWeapon().getDmg()*2) {
                    cout << enemy.getName() << " attacks " << player.getSummonedMon()[enemyTarget-1].getName() << " for " << dmgDone << "* DMG! (Critical HIT)" << endl << endl;
                } else {
                    cout << enemy.getName() << " attacks " << player.getSummonedMon()[enemyTarget-1].getName() << " for " << dmgDone << " DMG!" << endl << endl;
                }
            }

            // Increment turn-based values (now that players turn is over)
            if(player.getCastingStatus()) spellInfo->timeElapsed++;
            turnCount++;

            // Add mana per turn
            if(player.getMana() + MANA_REGEN > player.getMaxMana()) {
                player.setMana(player.getMaxMana());
            } else {
                player.setMana(player.getMana() + MANA_REGEN);
            }
        }
    } while(player.isAlive() && enemy.isAlive());

    // If the player wins
    if(!enemy.isAlive()) {
        cout << "\nCongratulations! You have successfully won the battle against " << enemy.getName() << "!" << endl;

        // Drop enemy loot
        if(enemy.dropItem()) {
            cout << "You have received the following item: " << enemy.getCurrentWeapon().getName() << endl;
            player.addItem(enemy.getCurrentWeapon());
        }

        // Get cash reward
        int cashPrize = rand() % 500;
        player.setCurrency(cashPrize + player.getCurrency());
        cout << "You have recieved $" << cashPrize << " for your efforts!" << endl;

        cout << "\nReturning to Main Menu..." << endl;

    // If the player loses
    } else if(!player.isAlive()) {
        cout << "\nUh oh! You have been defeated by " << enemy.getName() << ". You have lost everything and all progress." << endl;
        cout << "\nReturning to Main Menu..." << endl;
    }

    // Reset player values
    player.setHealth(player.getTotalHealth());
    player.setMana(player.getMaxMana());
    player.setCastingStatus(false);
    player.setMonCount(0);
    player.getSummonedMon().clear();

    delete spellInfo;
}

void GameMaster::shop() {
    cout << "View shop" << endl;
}

void GameMaster::viewInventory() {
    int inventoryChoice;
    Player &player = data.getPlayer();

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

                            if(viewSpell >= 1 && viewSpell <= player.getSpellBookSize()) {
                                Spell_Viewer viewSpellStats;
                                Spell showSpell = player.getSpell(viewSpell - 1);

                                viewSpellStats.displayDescription(showSpell);
                            } else {
                                outputError();
                            }

                        } while(viewSpell < 1 || viewSpell > player.getSpellBookSize());
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
    Player &player = data.getPlayer();
    if(player.getInventorySize() == 0) {
        cout << "Your inventory is empty, nothing to equip." << endl;
        return;
    }
    else {
        // Display inventory
        cout << "Your Weapons:" << endl;
        player.showInventory(); // Show available weapons

        int choice;
        cout << "Select the number of the weapon to equip (or 0 to cancel): ";
        cin >> choice;
        fixBuffer();

        // Validate input
        if (choice < 0 || choice > player.getInventorySize()) {
            cout << "Invalid choice! Try again." << endl;
            return;
        }
        
        if (choice == 0) {
            cout << "Equip action canceled." << endl;
            return;
        }
    
        // Get current weapon
        Weapon oldWeapon = player.getCurrentWeapon();

        // Equip the new weapon
        player.equipItem(choice - 1);

        // Remove the new weapon from inventory
        player.removeItem(choice - 1);

        // Add the old weapon back into the inventory
        player.addItem(oldWeapon);

        cout << "You have equipped " << player.getCurrentWeapon().getName() << "!" << endl;

    }
}

// Error check the user input
void GameMaster::fixBuffer() {
    cin.clear();
    cin.ignore(256, '\n');
}

void GameMaster::outputError() {
    cout << "\nThat is not a valid command! Try again." << endl << endl;
}