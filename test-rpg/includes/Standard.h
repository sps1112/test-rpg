#ifndef STANDARD_H
#define STANDARD_H

// Standard Headers
#include <iostream>
#include <string>
#include <ios>
#include <limits>

namespace rpgText
{
    // Prints message on a single line without moving over
    void print(const char *message);
    void print(std::string message);
    void print(const float num, int isChar = 0);

    // Prints message on a single line and then moves to next line
    void log(const char *message);
    void log(std::string message);
    void log(const float num, int isChar = 0);

    // Gets Input from Keyboard
    int get_int();
    int get_int_prompt(const char *prompt);

    // Clears the input buffer to take a single value each time
    void clear_input();

} // namespace rpgText

#endif // !STANDARD_H
