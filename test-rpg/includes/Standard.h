#ifndef STANDARD_H
#define STANDARD_H

#include <iostream>
//for clear input
#include <ios>
#include <limits>

namespace rpgText
{
    // Prints message on a single line without moving over
    void Print(const char *message);
    void Print(std::string message);
    void Print(const float num, int isChar = 0);

    // Prints message on a single line and then moves to next line
    void Log(const char *message);
    void Log(std::string message);
    void Log(const float num, int isChar = 0);

    // Gets Input from Keyboard
    int GetInt();
    int GetIntWithPrompt(const char *prompt);

    // Clears the input buffer to take a single value each time
    void ClearInput();

} // namespace rpgText

#endif