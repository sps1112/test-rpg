#ifndef STANDARD_H
#define STANDARD_H

#include <iostream>

void Log(const char *message)
{
    std::cout << message << std::endl;
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

#endif