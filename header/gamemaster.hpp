#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "gamedata.hpp"
#include "player.hpp"

class GameMaster {
    private:
        GameData data;
    public:
        const GameData& getData();
        void mainMenu();
        void battle(Player &user);
        void shop();
        void viewInventory();
        void viewInventoryMenu();
        void equipItem();
        // Error check the user input
        void fixBuffer();
        void outputError();
};

#endif /* GAMEMASTER.HPP */
