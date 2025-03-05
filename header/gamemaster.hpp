#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "gamedata.hpp"

class GameMaster {
    private:
        GameData data;
    public:
        const GameData& getData();
        void mainMenu();
        void battle();
        void shop();
        void viewInventory();
        // Error check the user input
        void fixBuffer();
};

#endif /* GAMEMASTER.HPP */

