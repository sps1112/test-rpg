#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "Standard.h"
#include "ASCArt.h"

// Namespace for Printer Header
namespace rpgText
{
    // Prints consecutive n '-'
    void PrintDash(int n);

    // Prints an alphabet and its certain line
    void PrintLetter(const char c, int line = 0);

    // Prints a given word
    void PrintWord(const char *word);

    // Prints the Game title
    void PrintTitle();

    // Prints the Game Ending
    void PrintEnd();

    // Prints the main menu
    void PrintMenu(bool hasSaveGame);

} // namespace rpgText

#endif