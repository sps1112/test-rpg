#ifndef PRINTER_H
#define PRINTER_H

// Standard Headers
#include <iostream>

// Custom Headers
#include "Standard.h"
#include "ASCArt.h"

// Namespace for Printer Header
namespace rpgText
{
    // Prints consecutive n number of '-'
    void print_dash(int n);

    // Prints an alphabet and its certain line
    void print_letter(const char c, int line = 0);

    // Prints a given word
    void print_word(const char *word);

    // Prints the Game title
    void print_title();

    // Prints the Game Ending
    void print_end();

    // Prints the main menu
    void print_menu(bool hasSaveGame);

} // namespace rpgText

#endif // !PRINTER_H
