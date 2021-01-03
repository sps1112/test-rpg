// Include the header files
#include <iostream>

// TODO: Add and includes folder to fix relative path
// TODO: Port to Windows
#include "../includes/Standard.h"
#include "../includes/Printer.h"
#include "../includes/Character.h"
#include "../includes/Battle.h"

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
    rpgText::ClearInput();
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
        choice = rpgText::GetInt();
        rpgText::ClearInput();
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
            rpgText::Print("Select Again: ");
            break;
        }
    }
    rpgText::Log("");
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
    rpgText::Log("Game Started");
    rpgText::Player player("../data/Player.char");
    player.PrintStats();
    while (isPlaying)
    {
        if (rpgText::CheckBattle(30))
        {
            rpgText::Log("You encountered an enemy");
            rpgText::StartBattle(player);
        }
        else
        {
            rpgText::Log("You are moving");
        }
        rpgText::Print("Enter 1 to continue or 0 to go back: ");
        playChoice = 2;
        while (playChoice != 0 && playChoice != 1)
        {
            playChoice = rpgText::GetInt();
            rpgText::ClearInput();
            switch (playChoice)
            {
            case 0:
                isPlaying = false;
                break;
            case 1:
                isPlaying = true;
                break;
            default:
                rpgText::Print("Select again (1 to continue or 0 to go back): ");
                break;
            }
        }
    }
    rpgText::Log("");
    RunMainMenu();
}

// Options Menu Function
void RunOptions()
{
    bool isOnOptions = true;
    int optionChoice;
    while (isOnOptions)
    {
        rpgText::Log("Options is Running");
        rpgText::Print("Enter 1 to continue or 0 to go back: ");
        optionChoice = 2;
        while (optionChoice != 0 && optionChoice != 1)
        {
            optionChoice = rpgText::GetInt();
            rpgText::ClearInput();
            switch (optionChoice)
            {
            case 0:
                isOnOptions = false;
                break;
            case 1:
                isOnOptions = true;
                break;
            default:
                rpgText::Print("Select again (1 to continue or 0 to go back): ");
                break;
            }
        }
    }
    RunMainMenu();
}