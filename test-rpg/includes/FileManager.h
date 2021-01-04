#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <sstream>
#include "Standard.h"

namespace rpgText
{
    // Calculates length of character array
    int GetCharArrayLength(const char *charArray);
    int GetCharArrayLength(char *charArray);

    // Converts character Array to string
    std::string ConvertToString(const char *charArray);
    std::string ConvertToString(char *charArray);

    // Converts chararcter array to float ("70" to 70.0)
    float ConvertToFloat(const char *charArray);

    // Gets Single Line from a starting Index till '\n'
    char *GetLine(const char *charList, int startIndex);
    char *GetLine(char *charList, int startIndex);

    // Gets ending index of a line from a starting Index
    int GetLineEndIndex(const char *charList, int startIndex);
    int GetLineEndIndex(char *charList, int startIndex);

    // Gets starting index of next line from a starting Index
    int GetLineStartIndex(const char *charList, int startIndex);
    int GetLineStartIndex(char *charList, int startIndex);

    // Get starting Index of a char array in another char array
    int GetStartIndexString(char *mainCharArray, const char *targetCharArray);

    // Get ending Index of a char array in another char array
    int GetEndIndexString(char *mainCharArray, const char *targetCharArray);

} // namespace rpgText

#endif