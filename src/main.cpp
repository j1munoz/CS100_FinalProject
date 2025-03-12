#include <iostream>

#include "../header/gamemaster.hpp"

using namespace std;

int main() {
    int choice;     // Gets the user input
    GameMaster navigate;

    cout << "\nWelcome to A Villain's Revenge!" << endl << endl;
    
    do {
        navigate.mainMenu();
        cin >> choice;
        navigate.fixBuffer();

        if(choice == 1) {
            navigate.battle();
        }
        else if(choice == 2) {
            navigate.shop();
        }
        else if(choice == 3) {
            navigate.viewInventory();
        }
        else if(choice != 4) {
            navigate.outputError();
        }

    } while (choice != 4 && navigate.getData().getPlayer().isAlive());

    return 0;
}
