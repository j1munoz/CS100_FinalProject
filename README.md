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
We will be using C++ to code our project. Additionally, we will utilize GitHub for version control and VS Code as our chosen IDE to develop in. Valgrind is also a tool we will make use of to ensure the quality of our project has no memory leaks and errors. Lastly, we will also use [Draw.io](https://app.diagrams.net/) for flowcharting and UML Diagram documentation.

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

![CS-100 UML drawio](https://github.com/user-attachments/assets/3b2ad942-3ece-4248-ae36-24eb5d80eeeb)

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
