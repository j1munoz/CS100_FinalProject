#include "../header/gamemaster.hpp"
#include "../header/spell_viewer.hpp"
#include "../header/weapon_viewer.hpp"
#include "../header/player.hpp"
#include "../header/upgradesystem.hpp"
#include "../header/shop.hpp"
#include "../header/shop_viewer.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::right;

// Holds the information of the current spell in use
struct SpellInfo {
    SpellInfo(int time, Spell spell) : timeElapsed(time), spell(spell) {}

    int timeElapsed;
    Spell spell;
};

// Holds the information of the current stat wishing to upgrade
struct StatInfo {
    string statName;
    int statCost;
    int statUpgradeAmount;

    StatInfo(const string& name, const int& cost, const int& upgrade) : 
        statName(name), statCost(cost), statUpgradeAmount(upgrade) {}
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

void GameMaster::mainMenu() const {
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

void GameMaster::generateLevel(vector<Enemy> &enemies) {
    int enemiesToBattle = rand() % 3 + 1;  // Battle between 1-3 enemies

    for(int i = 0; i < enemiesToBattle; ++i) {
        int randomEnemyIndex = rand() % data.getEnemyList().size();
        enemies.push_back(data.getEnemyList()[randomEnemyIndex]);
    }
}

void GameMaster::battle() {
    const int HEALTH_BAR_LENGTH = 36;
    const int MANA_BAR_LENGTH = 20;
    const int MANA_REGEN = 10;

    SpellInfo *spellInfo = nullptr;
    vector<Enemy> enemies;
    bool stopBattle = false;  // For when the user exits or dies

    if(data.getLvlCount() == 1) {
        Enemy tutorialEnemy("Training Dummy", 150, 0, 5, Weapon("Stick Arm", "Common", 1, 11, 0), 75);
        enemies.push_back(tutorialEnemy);
    } else {
        generateLevel(enemies);
    }

    // We pass by reference so we can edit the actual values of Player
    Player &player = data.getPlayer();

    cout << "\nBattle - Level " << data.getLvlCount() << endl << endl;
    int turnCount = 1;

    for(int currEnemy = 0; currEnemy < enemies.size() && stopBattle == false; ++currEnemy) {
        do {
            cout << "Turn " << turnCount << endl << endl;
    
            cout << "Your Mana" << endl;
            cout << "====================" << endl;
            cout << setw(MANA_BAR_LENGTH / 2) << right; player.displayMana();
            cout << "\n====================" << endl;
    
            cout << "Your Health" << setw(HEALTH_BAR_LENGTH * 2) << right << enemies[currEnemy].getName() << endl;
            cout << "======================================" << setw(HEALTH_BAR_LENGTH + 10) << right << "======================================\n";
            cout << setw(HEALTH_BAR_LENGTH / 2) << right; player.displayHealth(); 
            cout << setw(HEALTH_BAR_LENGTH + 7) << right; enemies[currEnemy].displayHealth();  
            cout << "\n======================================" << setw(HEALTH_BAR_LENGTH + 10) << right << "======================================\n";
    
            // Display any summoned monsters on the field
            for(int i = player.getSummonedMon().size() - 1; i >= 0; --i) {
                Monster &minion = player.getSummonedMon()[i];
    
                if(minion.getLifetime() > minion.getMaxLifetime()) {
                    player.getSummonedMon().erase(player.getSummonedMon().begin() + i);
                    player.setMonCount(player.getSummonedMon().size());
                } else if(minion.isAlive()) {
                    cout << "\n" << minion.getName() << " Health (Lifetime: " 
                    << minion.getLifetime() << "/" << minion.getMaxLifetime() << ")" << endl;
                    cout << "======================================" << endl;
                    cout << setw(HEALTH_BAR_LENGTH / 2) << right; minion.displayHealth(); 
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
                if(player.getCastingStatus()) {     // Determine if the user is currently casting a spell
                    if(spellInfo->timeElapsed == spellInfo->spell.getCastTime()) {
                        player.setCastingStatus(false);
        
                        // Calculate damage done
                        float dmgValue = spellInfo->spell.getDmg() - enemies[currEnemy].getDefense();
                        float dmgDone = (dmgValue > 0) ? dmgValue : 0;
        
                        float healthValue = enemies[currEnemy].getHealth() - dmgDone;
                        float remainingHealth = (healthValue > 0) ? healthValue : 0;
        
                        enemies[currEnemy].setHealth(remainingHealth);
        
                        cout << endl;
                        cout << "You casted " << spellInfo->spell.getName() << " on " << enemies[currEnemy].getName() << " for " << dmgDone << " DMG!" << endl;
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
                            float dmgValue = player.useAttack() - enemies[currEnemy].getDefense();
                            float dmgDone = (dmgValue > 0) ? dmgValue : 0;
        
                            float healthValue = enemies[currEnemy].getHealth() - dmgDone;
                            float remainingHealth = (healthValue > 0) ? healthValue : 0;
        
                            enemies[currEnemy].setHealth(remainingHealth);
        
                            // Display damage done (critical hit or not)
                            cout << endl;
                            if(dmgValue + enemies[currEnemy].getDefense() == player.getCurrentWeapon().getDmg()*2) {
                                cout << "You have attacked the " << enemies[currEnemy].getName() << " for " << dmgDone << "* DMG! (Critical HIT)" << endl;
                            } else {
                                cout << "You have attacked the " << enemies[currEnemy].getName() << " for " << dmgDone << " DMG!" << endl;
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
                cout << "You have run away from the battle..." << endl;
                stopBattle = true;
                break;
            } else {
                // Invalid input
                outputError();
            }
    
            // Minions move
            if(playerTurnActive == false && player.getMonCount() != 0) {
                for(int i = 0; i < player.getMonCount(); ++i) {
                    Monster &currentMinion = player.getSummonedMon()[i];   // Current monster
                    currentMinion.setLifetime(currentMinion.getLifetime() + 1);
    
                    if(currentMinion.isAlive()) {
                        // Minion attack
                        float minionDmgValue = currentMinion.useAttack() - enemies[currEnemy].getDefense();
                        float minionDmgDone = (minionDmgValue > 0) ? minionDmgValue : 0;
        
                        float healthValue = enemies[currEnemy].getHealth() - minionDmgDone;
                        float remainingHealth = (healthValue > 0) ? healthValue : 0;
        
                        enemies[currEnemy].setHealth(remainingHealth);
        
                        // Display damage done (critical hit or not)
                        if(minionDmgValue + enemies[currEnemy].getDefense() == currentMinion.getCurrentWeapon().getDmg()*2) {
                            cout << currentMinion.getName() << " attacks " << enemies[currEnemy].getName() << " for " << minionDmgDone << "* DMG! (Critical HIT)" << endl;
                        } else {
                            cout << currentMinion.getName() << " attacks " << enemies[currEnemy].getName() << " for " << minionDmgDone << " DMG!" << endl;
                        }
                    }
                }
            }
    
            // Enemy attacks back
            if(enemies[currEnemy].isAlive() && playerTurnActive == false) {
                int enemyTarget = player.getMonCount() != 0 ? (rand() % player.getMonCount()) + 1 : 1;
    
                // Enemy attacks player; else minion
                if(enemyTarget == 1) {
                    float dmgValue = enemies[currEnemy].useAttack() - player.getDefense();
                    float dmgDone = (dmgValue > 0) ? dmgValue : 0;
    
                    float healthValue = player.getHealth() - dmgDone;
                    float remainingHealth = (healthValue > 0) ? healthValue : 0;
    
                    player.setHealth(remainingHealth);
    
                    // Display damage done (critical hit or not)
                    if(dmgValue + player.getDefense() == enemies[currEnemy].getCurrentWeapon().getDmg()*2) {
                        cout << enemies[currEnemy].getName() << " attacks YOU for " << dmgDone << "* DMG! (Critical HIT)" << endl << endl;
                    } else {
                        cout << enemies[currEnemy].getName() << " attacks YOU for " << dmgDone << " DMG!" << endl << endl;
                    }
                } else {
                    Monster &attackedMinion = player.getSummonedMon()[enemyTarget - 1];
                    float dmgValue = enemies[currEnemy].useAttack() - attackedMinion.getDefense();
                    float dmgDone = (dmgValue > 0) ? dmgValue : 0;
    
                    float healthValue = attackedMinion.getHealth() - dmgDone;
                    float remainingHealth = (healthValue > 0) ? healthValue : 0;
    
                    attackedMinion.setHealth(remainingHealth);
    
                    // Display damage done (critical hit or not)
                    if(dmgValue + attackedMinion.getDefense() == enemies[currEnemy].getCurrentWeapon().getDmg()*2) {
                        cout << enemies[currEnemy].getName() << " attacks " << attackedMinion.getName() << " for " << dmgDone << "* DMG! (Critical HIT)" << endl << endl;
                    } else {
                        cout << enemies[currEnemy].getName() << " attacks " << attackedMinion.getName() << " for " << dmgDone << " DMG!" << endl << endl;
                    }
                }
    
                // Increment turn-based values (now that players turn is over)
                if(player.getCastingStatus()) spellInfo->timeElapsed++;
    
                // Add mana per turn
                if(player.getMana() + MANA_REGEN > player.getMaxMana()) {
                    player.setMana(player.getMaxMana());
                } else {
                    player.setMana(player.getMana() + MANA_REGEN);
                }
            }
        } while(player.isAlive() && enemies[currEnemy].isAlive() && stopBattle == false);
    
        turnCount++;
        // If the player wins
        if(!enemies[currEnemy].isAlive()) {
            cout << "\nCongratulations! You have successfully won the battle against " << enemies[currEnemy].getName() << "!" << endl;
    
            // Drop enemy loot
            if(enemies[currEnemy].dropItem()) {
                cout << "You have received the following item: " << enemies[currEnemy].getCurrentWeapon().getName() << endl;
                player.addItem(enemies[currEnemy].getCurrentWeapon());
            }
    
            // Get cash reward
            int cashPrize = rand() % 500;
            player.setCurrency(cashPrize + player.getCurrency());
            cout << "You have recieved $" << cashPrize << " for your efforts!" << endl;
    
            // Get experience points
            int experience = rand() % 31 + 40;
            cout << "You have recieved " << experience << "xp points for your efforts!" << endl;
    
            // If the player reached 100 or more experience, give them a skill point
            if(experience + player.getExperience() >= 100) {
                player.setExperience((experience + player.getExperience()) % 100);     // Reset experience, but keep leftover
    
                cout << "You have gained 1 skill point!" << endl;
                player.setSkillPoints(player.getSkillPoints() + 1);
                cout << "Current skill points: " << player.getSkillPoints() << " point(s)" << endl;
            } else {
                player.setExperience(experience + player.getExperience());
            }
    
        // If the player loses
        } else if(!player.isAlive()) {
            cout << "\nUh oh! You have been defeated by " << enemies[currEnemy].getName() << ". You have lost everything and all progress." << endl;
    
            stopBattle = true;
    
            // Reset values upon death
            player.setCurrency(0);
            player.setExperience(0);
            player.setSkillPoints(0);
        }

        cout << "\nReturning to Main Menu..." << endl;
    }

    // Reset player values
    player.setHealth(player.getTotalHealth());
    player.setMana(player.getMaxMana());
    player.setCastingStatus(false);
    player.setMonCount(0);
    player.getSummonedMon().clear();

    // Increment level
    data.setLvlCount(data.getLvlCount() + 1);

    delete spellInfo;
}

void GameMaster::shop() {
    char userChoice;
    Player &player = data.getPlayer();
    Shop &shop = data.getShop();
    shop.fillShop(data.getBothLists());;
    Shop_Viewer view;

    cout << "You are now in the Shop." << endl;
    cout << "Currency: " << player.getCurrency() << endl;

    do {
        view.displayItems(shop.getItemsForSale());
        cout << "Select your Choice: ";
        cin >> userChoice;


        if (isdigit(userChoice)) {
            int index = userChoice - '0';
            shop.purchaseItem(index);

        }

    } while(userChoice != 'Q' && userChoice != 'q');
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

                if(toupper(viewItemChoice) == 'S') {    // View spell
                    if(player.getSpellBookSize() == 0) {
                        cout << "\nYour spell book is currently empty.\n" << endl;
                    } else {
                        player.showSpells();
                            
                        int viewSpell;
                        do {
                            cout << "Select the spell you would like to inspect: ";
                            cin >> viewSpell;
                            fixBuffer();

                            // Display the valid spell
                            if(viewSpell >= 1 && viewSpell <= player.getSpellBookSize()) {
                                Spell_Viewer viewSpellStats;
                                Spell showSpell = player.getSpell(viewSpell - 1);

                                viewSpellStats.displayDescription(showSpell);
                            } else {
                                outputError();
                            }

                        } while(viewSpell < 1 || viewSpell > player.getSpellBookSize());
                    }

                } else if(toupper(viewItemChoice) == 'W') { // Show weapons
                    if(player.getInventorySize() == 0) {
                        cout << "\nYour inventory is currently empty.\n" << endl;
                    } else {
                        player.showInventory();

                        int viewWeapon;
                        do {
                            cout << "Select the weapon you would like to inspect: ";
                            cin >> viewWeapon;
                            fixBuffer();

                            // Display a valid weapon
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

        } else if(inventoryChoice == 3) {
            if(player.getSkillPoints() == 0) {
                cout << "\nYou currently do not have any skill points to use. Returning...\n" << endl;
            } else {
                int skillPointMenu;
                vector<StatInfo> statInfo = {   // Holds the information of all stats
                    {"Health", 1, 5},
                    {"Mana", 1, 5},
                    {"Defense", 1, 1},
                    {"Monster Count", 3, 1}
                };

                do {
                    cout << "\nUpgrade Your Stats" << endl;
                    cout << "--------------------------------------" << endl;
                    cout << "1. Health        (+5): 1 Skill Point" << endl;
                    cout << "2. Mana          (+5): 1 Skill Point" << endl;
                    cout << "3. Defense       (+1): 1 Skill Point" << endl;
                    cout << "4. Monster Count (+1): 3 Skill Points" << endl;
                    cout << "5. Quit" << endl;
                    cout << "--------------------------------------\n" << endl;
                    cout << "You currently have " << player.getSkillPoints() << " skill point(s)" << endl;
                    cout << "Select the stat you want to upgrade (or quit): ";
                    cin >> skillPointMenu;
                    fixBuffer();
                    
                    // Execute if the user entered a valid choice
                    if(skillPointMenu >= 1 && skillPointMenu <= 4) {
                        StatInfo currentStat = statInfo[skillPointMenu - 1];
                        int decideUpgrade;

                        if(player.getSkillPoints() < currentStat.statCost) {
                            cout << "\nSorry, you do not have enough skill points to upgrade " << currentStat.statName << "." << endl;
                        } else {
                            do {
                                cout << "\nWould you like to upgrade " << currentStat.statName << " for " << currentStat.statCost << " skill point (<1> Yes, <2> No): ";
                                cin >> decideUpgrade;
                                fixBuffer();
    
                                // Upgrade the stat
                                if(decideUpgrade == 1) {
                                    UpgradeSystem upgradeStat;
    
                                    if(currentStat.statName == "Health") {
                                        upgradeStat.increaseHealth(player, player.getTotalHealth() + currentStat.statUpgradeAmount);
                                        player.setHealth(player.getTotalHealth());
                                    } else if(currentStat.statName == "Mana") {
                                        upgradeStat.increaseMana(player, player.getMaxMana() + currentStat.statUpgradeAmount);
                                        player.setMana(player.getMaxMana());
                                    } else if(currentStat.statName == "Defense") {
                                        upgradeStat.increaseDef(player, player.getDefense() + currentStat.statUpgradeAmount);
                                    } else if(currentStat.statName == "Monster Count") {
                                        upgradeStat.increaseMonsterCount(player, player.getMaxMonCount() + currentStat.statUpgradeAmount);
                                    }

                                    // Subtract the user's skill points by the cost of the upgrade
                                    cout << "\nSuccessfully upgraded " << currentStat.statName << " by +" << currentStat.statUpgradeAmount << "!" << endl << endl;
                                    player.setSkillPoints(player.getSkillPoints() - currentStat.statCost);
                                    if(player.getSkillPoints() == 0) {
                                        // Exit the menu since the user has no skill points available to spend
                                        skillPointMenu = 5;
                                    }
                                } else if(decideUpgrade != 2) {
                                    outputError();
                                }
                            } while(decideUpgrade != 1 && decideUpgrade != 2);
                        }
                    } else if(skillPointMenu != 5) {
                        outputError();
                    }
                } while(skillPointMenu != 5);
            }
        } else if(inventoryChoice != 4) {
            outputError();
        }
    } while(inventoryChoice != 4);
}

void GameMaster::viewInventoryMenu() const {
    cout << "You are now in your inventory." << endl << endl;
    cout << "--------------------------" << endl;
    cout << "1. Equip Item" << endl;
    cout << "2. View Weapons/Spells" << endl;
    cout << "3. Upgrade Skills" << endl;
    cout << "4. Quit" << endl;
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
void GameMaster::fixBuffer() const {
    cin.clear();
    cin.ignore(256, '\n');
}

void GameMaster::outputError() const {
    cout << "\nThat is not a valid command! Try again." << endl << endl;
}
