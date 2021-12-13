// Include the header files
#include <iostream>

#include "Standard.h"
#include "Printer.h"
#include "Character.h"
#include "Battle.h"
#include "FileSystem.h"

// Function Declaration
void RunMainMenu();
void RunGame();
void RunOptions();

// Main Function
int main()
{
    rpgText::PrintTitle();
    RunMainMenu();
    rpgText::PrintEnd();
    int choice;
    std::cin >> choice;
    rpgText::clear_input();
    return 0;
}

// Main Menu Function
void RunMainMenu()
{
    bool hasSavedGame = false;
    bool hasChosen = false;
    int choice{0};
    rpgText::PrintMenu(hasSavedGame);
    while (!hasChosen)
    {
        choice = rpgText::get_int();
        rpgText::clear_input();
        switch (choice)
        {
        case 1:
            hasChosen = true;
            break;
        case 2:
            hasChosen = true;
            break;
        case 3:
            hasChosen = true;
            break;
        default:
            hasChosen = false;
            rpgText::print("Select Again: ");
            break;
        }
    }
    rpgText::log("");
    switch (choice)
    {
    case 1:
        RunGame();
        break;
    case 2:
        RunOptions();
        break;
    case 3:
        break;
    }
}

// Game Loop Function
void RunGame()
{
    bool isPlaying = true;
    int playChoice;
    rpgText::log("Game Started");
    rpgText::Player player(FileSystem::get_path("test-rpg/data/Player.char").c_str());
    player.PrintStats();
    while (isPlaying)
    {
        if (rpgText::CheckBattle(30))
        {
            rpgText::log("You encountered an enemy");
            rpgText::StartBattle(player);
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
    RunMainMenu();
}

// Options Menu Function
void RunOptions()
{
    bool isOnOptions = true;
    int optionChoice;
    while (isOnOptions)
    {
        rpgText::log("Options is Running");
        rpgText::print("Enter 1 to continue or 0 to go back: ");
        optionChoice = 2;
        while (optionChoice != 0 && optionChoice != 1)
        {
            optionChoice = rpgText::get_int();
            rpgText::clear_input();
            switch (optionChoice)
            {
            case 0:
                isOnOptions = false;
                break;
            case 1:
                isOnOptions = true;
                break;
            default:
                rpgText::print("Select again (1 to continue or 0 to go back): ");
                break;
            }
        }
    }
    RunMainMenu();
}