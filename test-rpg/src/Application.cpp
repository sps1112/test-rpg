// Custom Headers
#include "Standard.h"
#include "Printer.h"
#include "Character.h"
#include "Battle.h"
#include "FileSystem.h"
#include "MathEngine.h"

// Standard Headers
#include <iostream>

// Game Data

// All the game modes
enum GAME_STATE
{
    STATE_MENU,    // Main Menu
    STATE_OPTIONS, // Options Menu
    STATE_QUIT,    // Quit Menu
    STATE_MAP,     // Map Menu
    STATE_BATTLE,  // Battle Menu
    STATE_PAUSE,   // Pause Menu
};
GAME_STATE state = STATE_MENU; // Current State of the Game

// Whether there is save data available
bool hasSavedGame = false;
// Is the game running
bool toRun = true;

// Player Character
rpgText::Player player(FileSystem::get_path("test-rpg/data/Player.char").c_str());

// Function Declaration

void game_loop();
void run_main_menu();
void run_options();
void quit_game();
void run_game();
void start_battle();
void pause_game();

// Main Function
int main()
{
    game_loop();
    return 0;
}

// Runs the game loop
void game_loop()
{
    while (toRun)
    {
        rpgText::clear_screen();
        switch (state)
        {
        case STATE_MENU:
            run_main_menu();
            break;
        case STATE_OPTIONS:
            run_options();
            break;
        case STATE_QUIT:
            quit_game();
            toRun = false;
            break;
        case STATE_MAP:
            run_game();
            break;
        default:
            toRun = false;
        }
    }
}

// Main Menu Function
void run_main_menu()
{
    rpgText::print_title();
    rpgText::print_menu(hasSavedGame);
    int choice = -1;
    while (choice == -1)
    {
        choice = rpgText::get_int();
        switch (choice)
        {
        case 1:
        case 2:
        case 3:
            break;
        default:
            choice = -1;
            rpgText::print("Wrong option! Select Again: ");
        }
    }
    rpgText::new_line();
    switch (choice)
    {
    case 1:
        state = STATE_MAP;
        break;
    case 2:
        state = STATE_OPTIONS;
        break;
    case 3:
        state = STATE_QUIT;
        break;
    }
}

// Options Menu Function
void run_options()
{
    rpgText::print_options();
    int choice = -1;
    while (choice == -1)
    {
        choice = rpgText::get_int();
        switch (choice)
        {
        case 1:
        case 2:
            break;
        default:
            choice = -1;
            rpgText::print("Wrong option! Select Again: ");
        }
    }
    rpgText::new_line();
    if (choice == 1)
    {
        player.print_stats();
        choice = rpgText::get_int_prompt("Enter any number to go back to menu: ");
    }
    state = STATE_MENU;
}

// Quits the Game
void quit_game()
{
    rpgText::print_end();
    int choice = rpgText::get_int();
    rpgText::clear_screen();
}

// Game Loop Function
void run_game()
{
    bool gameRunning = true;
    rpgText::log("You have landed on a new world! This is you character:-");
    rpgText::log("");
    player.print_stats();
    rpgText::log("");
    while (gameRunning)
    {
        int choice = -1;
        rpgText::log("What do you want to do?");
        rpgText::log("1-> Travel to a new location");
        rpgText::log("2-> Pause the game to access options");
        rpgText::log("3-> Quit to Main Menu");
        rpgText::print("Choose by entering linked number:- ");
        while (choice == -1)
        {
            choice = rpgText::get_int();
            switch (choice)
            {
            case 1:
            case 2:
            case 3:
                break;
            default:
                choice = -1;
                rpgText::print("Wrong option! Select Again: ");
                break;
            }
        }
        rpgText::clear_screen();
        if (choice == 1)
        {
            choice = -1;
            rpgText::log("Choose one of the 4 directions to move in:- ");
            rpgText::log("1-> North");
            rpgText::log("2-> East");
            rpgText::log("3-> South");
            rpgText::log("4-> West");
            rpgText::print("Choose by entering linked number:- ");
            while (choice == -1)
            {
                choice = rpgText::get_int();
                switch (choice)
                {
                case 1:
                    rpgText::log("You moved North");
                    break;
                case 2:
                    rpgText::log("You moved East");
                    break;
                case 3:
                    rpgText::log("You moved South");
                    break;
                case 4:
                    rpgText::log("You moved West");
                    break;
                default:
                    choice = -1;
                    rpgText::print("Wrong option! Select Again: ");
                }
            }
            rpgText::print_line();
            rpgText::new_line();
            for (int i = 0; i < 10; i++)
            {
                if (rpgText::check_event(20))
                {
                    state = STATE_BATTLE;
                    start_battle();
                    if (state == STATE_MENU)
                    {
                        player.reset_stats();
                        gameRunning = false;
                        break;
                    }
                }
            }
        }
        else if (choice == 2)
        {
            state = STATE_PAUSE;
            pause_game();
        }
        else if (choice == 3)
        {
            state = STATE_MENU;
            gameRunning = false;
        }
        rpgText::clear_screen();
    }
}

void start_battle()
{
    rpgText::clear_screen();
    rpgText::log("You encountered an enemy");
    rpgText::print_line();
    rpgText::initiate_battle(player);
    rpgText::print_line();
    state = (player.get_status()) ? STATE_MAP : STATE_MENU;
}

void pause_game()
{
    rpgText::print_pause();
    int choice = -1;
    while (choice == -1)
    {
        choice = rpgText::get_int();
        switch (choice)
        {
        case 1:
        case 2:
            break;
        default:
            choice = -1;
            rpgText::print("Wrong option! Select Again: ");
        }
    }
    rpgText::new_line();
    if (choice == 1)
    {
        player.print_stats();
        choice = rpgText::get_int_prompt("Enter any number to go back to map: ");
    }
    state = STATE_MAP;
}
