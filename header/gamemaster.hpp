#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

class GameMaster {
    private:

    public:
        void mainMenu();
        void battle();
        void shop();
        void viewInventory();
        // Error check the user input
        void fixBuffer();
};

#endif /* GAMEMASTER.HPP */

