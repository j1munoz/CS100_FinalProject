# A Villain's Revenge
Authors: [Draylend Chow](https://github.com/Draylend), [Jimmy Munoz](https://github.com/j1munoz), [Kevin Abraham](https://github.com/RJKS100), and [Chris Whall](https://github.com/WorthyC)

## Project Description
**A Villain's Revenge** is an endless roguelite text-based adventure game. Compared to traditional games where the player is the hero, this time the user will _be_ the villain. In this role, they will summon monsters, cast spells, and upgrade items to seek revenge on the world. By playing from the perspective of the bad guy, hopefully people will see the villain isn't as evil all along.

### Gameplay Overview (Input/Output)
At the start of logging in, the user will be prompted with a main menu. Here, they can select to play, equip/change their equipment, and/or go to the shop. Depending on the chosen option, a new prompt will appear listing the respective choices. For example, if the user chooses to shop, a new screen will appear displaying all items available to buy and their current money amount. The user can now enter an item's number to buy or quit. If the user wishes to buy an item, a confirmation will be asked, and if agreed again, a "receipt" will be shown and the user may buy more items after. If the user has insufficient funds, they will be denied.

When the user begins the game, a randomly generated area will be chosen with its respective enemy types. It will show the player's health, enemy health, and resource meter. The player can choose from a list of options: attack, items, or quit. When attacking, they can summon a monster or cast a spell. Both actions require mana (which generates after every turn). If the user summons a monster, a text will display individually showing that monster's choice of attack every turn. Additionally, it's own health bar will also appear on screen. If the user chooses to cast a spell, they will have the option to choose a target to attack at. After the user attacks (and summoned monsters), the enemy's turn begins. The screen will display the current health of enemies and display the enemies attacks and damage numbers. When an enemy dies, it has a chance to drop an item; a text will be displayed notifying the player an item has been added to their inventory. This cycle continues until all enemies are defeated or the user loses. In a roguelite format, there is no "end goal", it is an endless gameplay cycle. The game will end when the user loses (no more health) or quits. The user can now buy new items from the shop or check out monster drops and get stronger each run.

### Features:
- Start Screen / Main Menu
- User Menu during gameplay (attack, item, or quit)
- Permadeath
- Endless Levels
- Shop System w/ Money
- Unique Monsters, Spells, and Enemies
- Upgrading System
- ~~Randomly Generated Levels (towns, forests, castles, etc.)~~
- ~~Random Events~~
- ~~Files to Save Progress~~

### Importance
Video games have been a large part of our lives growing up. Not only as a source of entertainment, but an outlet to explore our interests, partake in strategic planning, and a fun medium to bond with friends. When used correctly, they can be a great source to connect with others. We think creating our own video game would be a fun idea to try and appreciate all the planning and development that goes into making one. Compared to the functionality of other programs who have a determined purpose, a video game is less rigid in the application of it. It's main goal is to bring fun, and arguably, that can be the hardest thing to achieve sometimes. A video game is the perfect challenge to tackle and have fun with.

### Languages and Technologies
We will be using C++ to code our project. Additionally, we will utilize GitHub for version control and VS Code as our chosen IDE to develop in. Valgrind and the Googletest framework are tools we will make use of to ensure the quality of our project has no memory leaks and errors. Lastly, we will also use [Draw.io](https://app.diagrams.net/) for flowcharting and UML Diagram documentation.

## User Interface Specification

### Navigation Diagram
In this navigation diagram, the user will be greeted with a main menu screen upon entering the program. They will have the option to battle, go to the shop, or view/select their equipment. This is the resting area of the program. Both the shop and equip screen will be in a loop if the user continues to keep staying. Once they quit, they will be brought back to the main menu.

If the user chooses to battle, they will be taken to a new screen with new prompts. Here, they have the option to fight, view inventory, or quit. They repeat these options until the user quits, wins, or loses. Either outcome, they will be brought back to the main menu to repeat all actions again.

![CS-100 Navigation drawio](https://github.com/user-attachments/assets/ab4ddf07-1b55-4bc5-97cc-a7e9fc5826e2)

### Screen Layouts
In these Screen Layouts, we can see an example of what the game will look like when running.

A list of numbers divided by hypens represnts a menu of choices that the user may choose from. Looking at the image below, we can see the various screens the user will come across when running the program.

![CS-100 ScreenLayout drawio](https://github.com/user-attachments/assets/1281ce1c-553d-4ef5-9d06-a9498c72eb43)

## Class Diagram
Here is a UML Diagram of all the classes within our program. The blue boxes next to each class describe the class in more detail.

![CS-100 UML_2 0 drawio](https://github.com/user-attachments/assets/0c592727-7e3f-4739-8933-9284164f822b)

## Class Diagram with S.O.L.I.D. Principles
Here is an updated UML Diagram of all the classes within our program using S.O.L.I.D principles. Classes in RED denote new classes made as a result to not violate any principles. Yellow Notes are new descriptions for the newly added classes.

![CS-100 UML_SOLID drawio](https://github.com/user-attachments/assets/db8a742d-7171-449e-91a7-0f14778195a1)
*Note: To avoid cluttering, the notes with the class descriptions can be found [here](https://github.com/user-attachments/assets/18974f37-20e9-46ea-9916-b79e0f869419).*

## S.O.L.I.D. Explanations

### Item Class
For the `Item` class we applied the SRP, OCP, LSP, and DIP. 

To apply the SRP, we separated the `displayDescription()` function from `Item` class and created a seperate class called `ItemViewer` so that the `Item` class only focuses on holding data for an item rather than doing output as well. Additionally, since `ItemViewer` serves as an abstract class, it follows the OCP by allowing further modification to the `ItemViwer` class without violating its core goal of displaying data to items. The LSP conforms to this class as well since we can replace the `ItemViewer` class with either `WeaponViewer` or `SpellViewer` and it will still output an item description. Lastly, the DIP is not violated since `ItemViewer` depends on an abstract class (`Item`) so it depends on a high-level module. 

This change allows us to write better code because it helps isolate the responsibilities of classes whilst also making debugging easier. Since all the classes are more centralized in their usage, it makes it easier to track problems as well as assign issues that don't have high dependency on other parts of the program.

### Player Class
For the `Player` class, we applied the SRP, ISP, and DIP.

To apply the SRP, we separated all the `increase[STAT]()` functions and `monster()` related functions to their own respective classes such as `UpgradeSystem` and `MonsterManager`. This way, the `Player` class focuses only on what the user should be able to do whilst having external sources, such as increasing stats and managing the summoned monsters be another classe responsiblity. To adhere to the ISP, we moved the `vector<Spell> spellBook` member variable from the abstract `Character` class to the `Player` class only. This is because not all entities will have spells and it would be useless to have a function that not all inherited class will use. Lastly, for the DIP, rather than having the `UpgradeSystem` depend on the Player class, we let it depend on the `Character` class so it can depend on a higher-level (abstract) module rather than the Player clas (which is more prone to change). This allows the class to not depend on concrete implementation.

This change allows us to write better code since we can focus more on the responsiblities of the player and worry about the other details, such as the skill points and monsters, at another time. The classes don't heavily depend on each other anymore in order for the program to function properly.

### Shop Class
For the `Shop` class we applied the SRP, OCP, LSP, AND DIP.

To apply the SRP, we seperated the `displayItems()` function from the `Shop` class and created a seperate class called `ShopViewer` whose sole purpose is to display the items currently in the shop. This allows the `Shop` class to just focus on maintaining, storing, removing, and fetching items without taking on another responsiblity such as output. For the OCP and LSP, it came as a result of adhereing to the DIP. Since the `ShopViewer` class depended on the `Shop` class, which was a lower-level module, we made a `InterFaceShop` class that was an abstract class. This way, `Shop` can inherit from it but `ShopViewer` can depend on an abstraction with no concrete implementation. Consequently, now `Shop` is open for modification without destroyign it's original goal (OCP) and it can be replaced with it's subclass (LSP) without violating it's responsiblity of maintaining items.

This change allows us to write better code because it allows our code to scale and grow without having any hard-coded areas. Before, changing something in the `Shop` class could very well require us to redo the `displayItems()` function. However, now that it's in its own class, we can isolate the functionality of the class and edit only what we need to. Even though we ended up making three more classes to manage, it allows our program to be more flexible and object-oriented.
 
## Screenshots
| Shop | View Item | Equip Item |
| :-------------: | :-------------: | :-------------: |
| ![shop](https://github.com/user-attachments/assets/f51d9a48-a6f0-454a-88b4-1288b3c09c19)| ![viewItem](https://github.com/user-attachments/assets/ab223d14-537e-48bb-bffa-1f67cd58a9bd) | ![equipItem](https://github.com/user-attachments/assets/4fa91548-ebf0-42ff-8ea8-39f0cdc23967) |

### Battle
![battle](https://github.com/user-attachments/assets/25603369-029b-4846-bd98-5256b8ae3703)

## Installation/Usage
To install and play the game, you will need an Integrated Development Environment (IDE), such as [Vistual Studio](https://visualstudio.microsoft.com/downloads/), [Eclipse](https://www.eclipse.org/downloads/), etc. to host the necessary files and run the program. You can manually download all the files, download a ZIP file, or clone the repository. After doing either, you must run the following commands in the terminal:
```
cmake .
make
bin/villain_revenge
```
After running the previous 3 commands, you will enter the game and must follow the promps on screen to play. If you exit the game, you may reenter the game using `bin/villain_revenge`.

This program is meant to be a text-based terminal game used for entertainment. There are some strategic elements involved that can allow the user to engage in critical thinking and planning. However, as with any game, it is meant purely as a recreational activity and merely just provides entertainment to help the user pass time and have fun.

## Testing
Our project was tested and validated using Valgrind and the Googletest framework.

### Valgrind
Valgrind is a programming tool useful for memory debugging, profiling, and leak detection. Using Valgrind, we were able to verify that our program had no memory leaks by using:
```
valgrind --leak-check=full --track-origins=yes ./[EXE_FILE]
```
After running this command, we were able to see the Heap Summary and any possible errors in the program. We can then trace the source of the memory leak and the type of error that causes this issue. This allows us to ensure that any allocated memory was properly freed / deallocated and no more memory errors remain in our program.

![valgrind](https://github.com/user-attachments/assets/014efa05-288c-4821-8251-d3f6f5f4e7f3)

### Googletest
The Googletest framework is a C++ testing and mocking framework to help developers write tests for their programs. Utilizing this, we can create Unit Tests for many of our foundational classes (like Player, Enemy, Monster, Spell, Weapon, etc.) and verify that each of the functions output the correct information they should compute. We can validate member variables and functional logic by testing their integrity to ensure they lead to our expected output.

![unit tests](https://github.com/user-attachments/assets/08da7d9c-6eb2-40c6-bf9f-5d5962d2b490)
