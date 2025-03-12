#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "gamedata.hpp"
#include "player.hpp"

class GameMaster {
    private:
        GameData data;
    public:
        GameData& getData();
        void mainMenu() const;
        void battle();
        void shop();
        void viewInventory();
        void viewInventoryMenu() const;
        void equipItem();
        // Error check the user input
        void fixBuffer() const;
        void outputError() const;
};

#endif /* GAMEMASTER.HPP */
