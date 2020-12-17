#include <iostream>

#include "../includes/Standard.h"
#include "../includes/Printer.h"

void RunMainMenu();
void RunGame();
void RunOptions();
void RunBattle();

int main()
{
    rpgPrinter::PrintTitle();
    RunMainMenu();
    rpgPrinter::PrintEnd();
    int choice;
    std::cin >> choice;
    return 0;
}

void RunMainMenu()
{
    bool hasSavedGame = false;
    bool hasChosen = false;
    int choice;
    rpgPrinter::PrintMenu(hasSavedGame);
    while (!hasChosen)
    {
        std::cin >> choice;
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
            Print("Select Again: ");
            break;
        }
    }
    Log("");
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

void RunGame()
{
    bool isPlaying = true;
    int playChoice;
    while (isPlaying)
    {
        Log("Game is Running");
        Log("");
        Log("Enter 1 to continue or 0 to go back");
        playChoice = 2;
        while (playChoice != 0 && playChoice != 1)
        {
            std::cin >> playChoice;
            switch (playChoice)
            {
            case 0:
                isPlaying = false;
                break;
            case 1:
                isPlaying = true;
                break;
            default:
                Print("Select again (1 to continue or 0 to go back): ");
                break;
            }
        }
    }
    Log("");
    RunMainMenu();
}

void RunOptions()
{
    bool isOnOptions = true;
    int optionChoice;
    while (isOnOptions)
    {
        Log("Options is Running");
        Log("");
        Log("Enter 1 to continue or 0 to go back");
        optionChoice = 2;
        while (optionChoice != 0 && optionChoice != 1)
        {
            std::cin >> optionChoice;
            switch (optionChoice)
            {
            case 0:
                isOnOptions = false;
                break;
            case 1:
                isOnOptions = true;
                break;
            default:
                Print("Select again (1 to continue or 0 to go back): ");
                break;
            }
        }
    }
    RunMainMenu();
}

void RunBattle()
{
    // Battle code
}
