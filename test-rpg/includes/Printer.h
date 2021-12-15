#ifndef PRINTER_H
#define PRINTER_H

// Custom Headers
#include "Standard.h"
#include "ASCArt.h"

// Standard Headers
#include <iostream>

// Namespace for Printer Header
namespace rpgText
{
    // Skips to a new line in output
    void new_line();

    // Prints consecutive n number of '-'
    void print_dash(int n);

    // Prints a line of 15 Dashes
    void print_line();

    // Prints an alphabet and its certain line
    void print_letter(const char c, int line = 0);

    // Prints a given word
    void print_word(const char *word);

    // Prints a number with label
    void print_data(const char *label, int n);

    // Prints the Game title
    void print_title();

    // Prints the Game Ending
    void print_end();

    // Prints the main menu
    void print_menu(bool hasSaveGame);

    // Prints the option menu
    void print_options();

    // Prints the pause menu
    void print_pause();

} // namespace rpgText

#endif // !PRINTER_H
