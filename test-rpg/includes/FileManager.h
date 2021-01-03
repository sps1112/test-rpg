#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include "Standard.h"

namespace rpgText
{
    int GetCharArrayLength(const char *charArray)
    {
        int index = 0;
        while ((char)charArray[index] != '\0')
        {
            index++;
        }
        return (index + 1);
    }

    int GetCharArrayLength(char *charArray)
    {
        int index = 0;
        while ((char)charArray[index] != '\0')
        {
            index++;
        }
        return (index + 1);
    }

    std::string ConvertToString(const char *charArray)
    {
        std::string s = "";
        for (int i = 0; i < GetCharArrayLength(charArray); i++)
        {
            s = s + charArray[i];
        }
        return s;
    }

    std::string ConvertToString(char *charArray)
    {
        std::string s = "";
        for (int i = 0; i < GetCharArrayLength(charArray); i++)
        {
            s = s + charArray[i];
        }
        return s;
    }

    float ConvertToFloat(const char *charArray)
    {
        std::string s = ConvertToString(charArray);
        std::stringstream ss(s);
        float value{0};
        ss >> value;
        return value;
    }

    char *GetLine(const char *charList, int startIndex)
    {
        char *newLine = new char[GetCharArrayLength(charList)];
        int index = startIndex;
        while ((char)charList[index] != '\n')
        {
            newLine[index - startIndex] = charList[index];
            index++;
        }
        newLine[index - startIndex] = '\0';
        return newLine;
    }

    char *GetLine(char *charList, int startIndex)
    {
        char *newLine = new char[GetCharArrayLength(charList)];
        int index = startIndex;
        int count = 0;
        while ((char)charList[index] != '\n' && (char)charList[index] != '\0')
        {
            newLine[index - startIndex] = charList[index];
            index++;
        }
        newLine[index - startIndex] = '\0';
        return newLine;
    }

    int GetLineEndIndex(const char *charList, int startIndex)
    {
        int index = startIndex;
        while ((char)charList[index] != '\n')
        {
            index++;
        }
        return index;
    }

    int GetLineEndIndex(char *charList, int startIndex)
    {
        int index = startIndex;
        while ((char)charList[index] != '\n')
        {
            index++;
        }
        return index;
    }

    int GetLineStartIndex(const char *charList, int startIndex)
    {
        return (GetLineEndIndex(charList, startIndex) + 1);
    }

    int GetLineStartIndex(char *charList, int startIndex)
    {
        return (GetLineEndIndex(charList, startIndex) + 1);
    }

    int GetStartIndexString(char *mainCharArray, const char *targetCharArray)
    {
        int mainLength = GetCharArrayLength(mainCharArray);
        int targetLength = GetCharArrayLength(targetCharArray);
        if (mainLength >= targetLength)
        {
            int index = 0;
            bool isChecking = false;
            bool hasIndex = false;
            int stringIndex = -1;
            int targetIndex = 0;
            while ((char)mainCharArray[index] != '\0')
            {
                if (isChecking)
                {
                    if (targetIndex < targetLength - 1)
                    {
                        if (mainCharArray[index] != targetCharArray[targetIndex])
                        {
                            isChecking = false;
                        }
                    }
                    else
                    {
                        hasIndex = true;
                        stringIndex = index - (targetLength - 1);
                        break;
                    }
                }
                if (!isChecking)
                {
                    if (mainCharArray[index] == targetCharArray[0])
                    {
                        isChecking = true;
                        targetIndex = 0;
                    }
                }
                index++;
                if (isChecking)
                {
                    targetIndex++;
                }
            }
            return stringIndex;
        }
        Log("INVALID TARGET STRING");
        return -1;
    }

    int GetEndIndexString(char *mainCharArray, const char *targetCharArray)
    {
        int mainLength = GetCharArrayLength(mainCharArray);
        int targetLength = GetCharArrayLength(targetCharArray);
        if (mainLength >= targetLength)
        {
            int index = GetStartIndexString(mainCharArray, targetCharArray);
            index += targetLength - 1;
            return index;
        }
        Log("INVALID TARGET STRING");
        return -1;
    }
} // namespace rpgText

#endif