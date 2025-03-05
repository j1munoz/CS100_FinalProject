#include <iostream>
#include "../header/gamedata.hpp"
#include "../header/gamemaster.hpp"
#include "../header/player.hpp"
#include "../header/character.hpp"
#include "../header/enemy.hpp"
#include "../header/item.hpp"
#include "../header/weapon_viewer.hpp"
#include "../header/spell_viewer.hpp"

using namespace std;

void outputError() {
    cout << "\nThat is not a valid command! Try again." << endl << endl;
}

int main() {
    int choice;     // Gets the user input
    Player *player = new Player;
    Player user;
    GameMaster navigate;

    cout << "\nWelcome to A Villain's Revenge!" << endl << endl;
    
    do {
        navigate.mainMenu();
        cin >> choice;
        navigate.fixBuffer();

        if(choice == 1) {
            navigate.battle(user);
        }
        else if(choice == 2) {
            navigate.shop();
        }
        else if(choice == 3) {
            navigate.viewInventory();
        }
        else if(choice != 4) {
            outputError();
        }

    } while (choice != 4 && player->isAlive());
    
    // Delete dynamically created objects/variables
    delete player;

    return 0;
}
