// Custom Headers
#include "Standard.h"
#include "Printer.h"
#include "Character.h"
#include "Battle.h"
#include "FileSystem.h"

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
        case STATE_BATTLE:
            start_battle();
            break;
        case STATE_PAUSE:
            pause_game();
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
    bool hasChosen = false;
    int choice = 0;
    rpgText::print_menu(hasSavedGame);
    while (!hasChosen)
    {
        choice = rpgText::get_int();
        rpgText::clear_input();
        switch (choice)
        {
        case 1:
        case 2:
        case 3:
            hasChosen = true;
            break;
        default:
            hasChosen = false;
            rpgText::print("Select Again: ");
        }
    }
    rpgText::log("");
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
    bool hasChosen = false;
    int choice = 0;
    while (!hasChosen)
    {
        choice = rpgText::get_int();
        rpgText::clear_input();
        switch (choice)
        {
        case 1:
        case 2:
            hasChosen = true;
            break;
        default:
            hasChosen = false;
            rpgText::print("Select Again: ");
        }
    }
    rpgText::log("");
    if (choice == 1)
    {
        player.print_stats();
        rpgText::print("Enter any number to go back to menu: ");
        choice = rpgText::get_int();
        rpgText::clear_input();
    }
    state = STATE_MENU;
}

// Quits the Game
void quit_game()
{
    rpgText::print_end();
    int choice = rpgText::get_int();
    rpgText::clear_input();
    rpgText::clear_screen();
}

// Game Loop Function
void run_game()
{
    bool isPlaying = true;
    int playChoice;
    rpgText::log("Game Started");
    rpgText::print_line();
    player.print_stats();
    rpgText::log("");
    while (isPlaying)
    {
        if (rpgText::check_for_battle(30))
        {
            rpgText::log("You encountered an enemy");
            rpgText::initiate_battle(player);
        }
        else
        {
            rpgText::log("You are moving");
        }
        rpgText::print("Enter 1 to continue or 0 to go back: ");
        playChoice = 2;
        while (playChoice != 0 && playChoice != 1)
        {
            playChoice = rpgText::get_int();
            rpgText::clear_input();
            switch (playChoice)
            {
            case 0:
                isPlaying = false;
                break;
            case 1:
                isPlaying = true;
                break;
            default:
                rpgText::print("Select again (1 to continue or 0 to go back): ");
                break;
            }
        }
    }
    rpgText::log("");
    state = STATE_MENU;
}

void start_battle()
{
}

void pause_game()
{
}
