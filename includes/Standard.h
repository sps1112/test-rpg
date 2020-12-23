#ifndef STANDARD_H
#define STANDARD_H

#include <iostream>
//for clear input
#include <ios>
#include <limits>

// Prints message on a single line and then moves to next line
void Log(const char *message)
{
    std::cout << message << '\n'; // Prefer using '\n' instead of std::endl
}

void Log(std::string message)
{
    Log(message.c_str());
}

void Log(const float num, int isChar = 0)
{
    if (isChar)
    {
        char c = int(num);
        Log(std::string(1, c));
    }
    else
    {
        Log(std::to_string(num));
    }
}

// Prints message on a single line without moving over
void Print(const char *message)
{
    std::cout << message;
}

void Print(std::string message)
{
    Print(message.c_str());
}

void Print(const float num, int isChar = 0)
{
    if (isChar)
    {
        char c = int(num);
        Print(std::string(1, c));
    }
    else
    {
        Print(std::to_string(num));
    }
}

// Clears the input buffer to take a single value each time
void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif