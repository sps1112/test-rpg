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

void Log(const float num)
{
    Log(std::to_string(num));
}

#endif